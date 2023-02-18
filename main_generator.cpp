#include <cpr/cpr.h>
#include <iostream>
#include <string>
#include <vector>

struct type{
    std::string name;
    std::vector<std::string> parameter;
    std::vector<std::string> name_type;
};

struct types_telegram{
    std::vector<type> names;
};

int main(int argc, char** argv) {
    cpr::Response r = cpr::Get(cpr::Url{"https://core.telegram.org/bots/api"});
    auto text=r.text;
    auto types=text.substr(text.find("Available types"),text.find("\"InputFile\"")-text.find("Available types"));
    types_telegram typeTelegram;
    while(types.find("<i class=\"anchor-icon\"></i></a>")!=std::string::npos) {
        type line;
        std::string find_name = "<i class=\"anchor-icon\"></i></a>";
        std::string name = types.substr(types.find("<i class=\"anchor-icon\"></i></a>") + find_name.size(), 100);
        name = name.substr(0, name.find("<"));
        if(name.find(" ")==std::string::npos) {
            line.name = name;
            std::string tbody = types.substr(types.find("<tbody>"), types.find("</tbody>") - types.find("<tbody>"));
            types.erase(types.find("<tbody>"), 1);
            types.erase(types.find("</tbody>"), 1);
            while (tbody.find("<tr>") != std::string::npos) {
                std::string tr = tbody.substr(tbody.find("<tr>"), tbody.find("</tr>") - tbody.find("<tr>"));
                std::string param = tr.substr(tr.find("<td>") + 4, tr.find("</td>") - tr.find("<td>") - 4);
                line.parameter.push_back(param);
                tr.erase(tr.find("<td>"), 1);
                tr.erase(tr.find("</td>"), 1);
                std::string typ = tr.substr(tr.find("<td>") + 4, tr.find("</td>") - tr.find("<td>") - 4);
                line.name_type.push_back(typ);
                tbody.erase(tbody.find("<tr>"), 1);
                tbody.erase(tbody.find("</tr>"), 1);
            }
            typeTelegram.names.push_back(line);
            if (typeTelegram.names.at(typeTelegram.names.size() - 1).name == "InputFile") {
                break;
            }
        }
        types.erase(types.find("<i class=\"anchor-icon\"></i></a>"),1);
    }
    std::string out="";
    for(auto nm : typeTelegram.names){
        out=out+"struct "+nm.name+"{\n";
        for(auto pa: nm.parameter){
            out=out + " std::string "+pa+";\n";
        }
        out=out+"};\n";
    }
    std::cout<<out;
    return 0;
}