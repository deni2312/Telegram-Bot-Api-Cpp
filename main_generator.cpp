#include <cpr/cpr.h>
#include <iostream>
#include <string>
#include <vector>

struct type{
    std::string name;
    std::vector<std::string> parameter;
    std::vector<std::string> name_type;
};

struct typess{
    std::vector<type> names;
};

int main(int argc, char** argv) {
    cpr::Response r = cpr::Get(cpr::Url{"https://core.telegram.org/bots/api"});
    auto text=r.text;
    auto types=text.substr(text.find("Available types"),text.find("\"InputFile\"")-text.find("Available types"));
    std::string find_name="<i class=\"anchor-icon\"></i></a>";
    std::string name=types.substr(types.find("<i class=\"anchor-icon\"></i></a>")+find_name.size(),100);
    name=name.substr(0,name.find("<"));
    typess t;
    std::string tbody=types.substr(types.find("<tbody>"),types.find("</tbody>")-types.find("<tbody>"));
    while(tbody.find("<tr>")!=std::string::npos){
        std::string tr=tbody.substr(tbody.find("<tr>"),tbody.find("</tr>")-tbody.find("<tr>"));
        std::string param=tr.substr(tr.find("<td>")+4,tr.find("</td>")-tr.find("<td>")-4);
        tr.erase(tr.find("<td>"),1);
        tr.erase(tr.find("</td>"),1);
        std::string typ=tr.substr(tr.find("<td>")+4,tr.find("</td>")-tr.find("<td>")-4);
        tbody.erase(tbody.find("<tr>"),1);
        tbody.erase(tbody.find("</tr>"),1);
    }
    std::vector<std::string> parameter;
    std::vector<std::string> name_type;
    return 0;
}