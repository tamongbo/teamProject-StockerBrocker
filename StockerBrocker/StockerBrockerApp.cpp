#pragma once
#include "Adapter.cpp"

class StockerBrocker {
public:
	void selectStockBrocker(Adapter* adapter) {
		this->adapter = adapter;
	}

	void login(string ID, string password) {
		adapter->login(ID, password);
	}

	void buy(string stockCode, int count, int price) {
		if (count <= 0)
			throw exception("StockerBrockerBuy0CountException");
		if (price <= 0)
			throw exception("StockerBrockerPriceException");

		adapter->buy(stockCode, count, price);
	}

	void sell(string stockCode, int count, int price) {
		adapter->sell(stockCode, count, price);
	}

	int currentPrice(string stockCode, int minutes) {
		return adapter->currentPrice(stockCode, minutes);
	}

	void sellNiceTiming(string stockCode, int price) {

	}

private:
	Adapter* adapter;
};