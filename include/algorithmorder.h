#ifndef ALGORITHMORDER_H
#define ALGORITHMORDER_H
#include<atomic>
#include"structs.hpp"
#include"strategytemplate.h"
class StrategyTemplate;
class AlgorithmOrder
{
public:
	AlgorithmOrder(StrategyTemplate*strategy);
	~AlgorithmOrder();
	void setUnitVolume(double unitVolume);
	void setTargetPos(const std::string &symbol, double volume);
	void setBacktestMode();
	void setCallback();

	void checkPosTick(const std::shared_ptr<Event_Tick> &tick);
	void checkPosBar(const jsstructs::BarData &bar);

private:
	clock_t starttime;
	double unitVolume;
	bool is_backtest;
	std::atomic_bool is_callback;
	StrategyTemplate *strategy;
	std::map<std::string, double>targetPosMap;		std::mutex targetPosMtx;
	std::map<std::string, std::vector<std::string>>symbol_mapping_orderIDlist;   std::mutex symbol_mapping_orderIDlistmtx;
};
#endif