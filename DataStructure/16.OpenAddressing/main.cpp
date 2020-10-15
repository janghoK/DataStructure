#include "OpenAddressing.hpp"

int main(void) {
	HashTable table(11);

	table.Set("AAPL", "Apple");
	table.Set("AMZN", "Amazon.com");
	table.Set("TSLA", "Tesla");
	table.Set("NVDA", "Nvidia");
	table.Set("MSFT", "Microsoft");
	table.Set("DIS", "Walt Disney");
	table.Set("FB", "Facebook");
	table.Set("GOOGL", "Alphabet A");
	table.Set("ZM", "Zoom video");
	table.Set("BABA", "Alibaba ADR");
	table.Set("GOOG", "Alphabet C");
	table.Set("APAC", "Apache org");
	table.Set("ZYMZZ", "Unisys Ops Check");

	std::cout << std::endl;
	std::cout << "key:AAPL, value:" << table.Get("AAPL") << std::endl;
	std::cout << "key:AMZN, value:" << table.Get("AMZN") << std::endl;
	std::cout << "key:TSLA, value:" << table.Get("TSLA") << std::endl;
	std::cout << "key:NVDA, value:" << table.Get("NVDA") << std::endl;
	std::cout << "key:MSFT, value:" << table.Get("MSFT") << std::endl;
	std::cout << "key:DIS, value:" << table.Get("DIS") << std::endl;
	std::cout << "key:FB, value:" << table.Get("FB") << std::endl;
	std::cout << "key:GOOGL, value:" << table.Get("GOOGL") << std::endl;
	std::cout << "key:ZM, value:" << table.Get("ZM") << std::endl;
	std::cout << "key:BABA, value:" << table.Get("BABA") << std::endl;
	std::cout << "key:GOOG, value:" << table.Get("GOOG") << std::endl;
	std::cout << "key:APAC, value:" << table.Get("APAC") << std::endl;
	std::cout << "key:ZYMZZ, value:" << table.Get("ZYMZZ") << std::endl;

	table.DestroyHashTable();
	return 0;
}
