#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

struct config {
    double a;
    double b;
};

config read_config(string& root) {
    string config_name = root + "/config.json";
	ifstream fi(config_name);
	if(fi.is_open()){
		json ji;
		fi >> ji;

        config cfg = {};

		if(ji.find("a") != ji.end()) {cfg.a = ji["a"];}
		if(ji.find("b") != ji.end()) {cfg.b = ji["b"];}

        return cfg;
	} else{
		cout << "File " << config_name << "  not found." << endl;
	}
}

void run(string& root, config& cfg) {
    double c = hypot(cfg.a, cfg.b);

    json result;
    result["c"] = c;

    string result_name = root + "/result.json";
    ofstream fo(result_name);
    fo << result;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Usage: hypot <prefix>" << endl;
        cout << "   <prefix>   Directory where ";
        cout << "config.json is located." << endl;
        return 1;
    }

    string root(argv[1]);
    auto cfg = read_config(root);

    run(root, cfg);
}
