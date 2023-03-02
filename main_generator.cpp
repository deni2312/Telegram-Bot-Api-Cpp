#include <cpr/cpr.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>

struct params {
    std::string parameter;
    std::string name_type;
    std::string return_type;
};

struct type {
    std::string name;
    std::string description;
    std::vector<params> n;
};

struct types_telegram {
    std::vector<type> names;
};

std::string normalize_type(std::string type) {
    if (type.find("Integer") != std::string::npos) {
        return "int";
    }
    if (type.find("Boolean") != std::string::npos) {
        return "bool";
    }
    if (type.find("String") != std::string::npos) {
        return "std::string";
    }
    if (type.find("Float") != std::string::npos) {
        return "float";
    }
    if (type.find("True") != std::string::npos) {
        return "bool";
    }
    if (type.find("False") != std::string::npos) {
        return "bool";
    }
    if (type.find("Array") != std::string::npos) {
        return "std::vector<std::shared_ptr<" +
               type.substr(type.find(">") + 1, type.find("<", type.find(">")) - type.find(">") - 1) + ">>";
    }
    if (type.find("<a href") != std::string::npos) {
        return "std::shared_ptr<" +
               type.substr(type.find(">") + 1, type.find("<", type.find(">")) - type.find(">") - 1) + ">";
    }

    return type;
}

std::string normalize_type1(std::string type) {
    if (type.find("Integer") != std::string::npos) {
        return "int";
    }
    if (type.find("Boolean") != std::string::npos) {
        return "bool";
    }
    if (type.find("String") != std::string::npos) {
        return "std::string";
    }
    if (type.find("Float") != std::string::npos) {
        return "float";
    }
    if (type.find("True") != std::string::npos) {
        return "bool";
    }
    if (type.find("False") != std::string::npos) {
        return "bool";
    }
    if (type.find("Array") != std::string::npos) {
        return "std::vector<" + type.substr(type.find(">") + 1, type.find("<", type.find(">")) - type.find(">") - 1) +
               ">";
    }
    if (type.find("<a href") != std::string::npos) {
        return type.substr(type.find(">") + 1, type.find("<", type.find(">")) - type.find(">") - 1);
    }

    return type;
}

std::string gets_default(std::string type) {
    if (type.find("Integer") != std::string::npos) {
        return "0";
    }
    if (type.find("Boolean") != std::string::npos) {
        return "false";
    }
    if (type.find("String") != std::string::npos) {
        return "\"\"";
    }
    if (type.find("Float") != std::string::npos) {
        return "0";
    }
    if (type.find("True") != std::string::npos) {
        return "false";
    }
    if (type.find("False") != std::string::npos) {
        return "false";
    }
    if (type.find("Array") != std::string::npos) {
        return "std::vector<std::shared_ptr<" +
               type.substr(type.find(">") + 1, type.find("<", type.find(">")) - type.find(">") - 1) + ">>()";
    }
    if (type.find("<a href") != std::string::npos) {
        return "nullptr";
    }

    return type;
}

void type_generator() {
    cpr::Response r = cpr::Get(cpr::Url{"https://core.telegram.org/bots/api"});
    auto text = r.text;
    auto types = text.substr(text.find("Getting updates"), text.size() - text.find("Getting updates"));
    types_telegram typeTelegram;
    while (types.find("<i class=\"anchor-icon\"></i></a>") != std::string::npos) {
        type line;
        std::string find_name = "<i class=\"anchor-icon\"></i></a>";
        std::string name = types.substr(types.find("<i class=\"anchor-icon\"></i></a>") + find_name.size(), 100);
        std::string description = types.substr(types.find("<p>", types.find("<i class=\"anchor-icon\"></i></a>")) + 3,
                                               types.find("</p>", types.find("<i class=\"anchor-icon\"></i></a>")) -
                                               types.find("<p>", types.find("<i class=\"anchor-icon\"></i></a>")) - 3);
        name = name.substr(0, name.find("<"));
        line.description = description;
        line.name = name;
        if (description.find("Currently holds no information") == std::string::npos &&
            (description.find("This object") != std::string::npos ||
             description.find("Represents") != std::string::npos ||
             description.find("Describes") != std::string::npos ||
             description.find("This <a href=\"#available-types\">object</a>") != std::string::npos)) {
            std::string tbody = types.substr(types.find("<tbody>", types.find("<i class=\"anchor-icon\"></i></a>")),
                                             types.find("</tbody>", types.find("<i class=\"anchor-icon\"></i></a>")) -
                                             types.find("<tbody>", types.find("<i class=\"anchor-icon\"></i></a>")));
            while (tbody.find("<tr>") != std::string::npos) {
                std::string tr = tbody.substr(tbody.find("<tr>"), tbody.find("</tr>") - tbody.find("<tr>"));
                std::string param = tr.substr(tr.find("<td>") + 4, tr.find("</td>") - tr.find("<td>") - 4);
                tr.erase(tr.find("<td>"), 1);
                tr.erase(tr.find("</td>"), 1);
                std::string typ = tr.substr(tr.find("<td>") + 4, tr.find("</td>") - tr.find("<td>") - 4);
                tbody.erase(tbody.find("<tr>"), 1);
                tbody.erase(tbody.find("</tr>"), 1);
                line.n.push_back({param, typ});
            }
        }
        if (line.description.find("Use this method") == std::string::npos &&
            line.description.find("Informs") == std::string::npos &&
            line.description.find("A simple method") == std::string::npos &&
            (name.find(" ") == std::string::npos || name.find("Array") != std::string::npos)) {
            typeTelegram.names.push_back(line);
        }
        types.erase(types.find("<i class=\"anchor-icon\"></i></a>"), 1);
    }
    std::string out = "";
    out = out +
          "#include <string>\n#include <memory>\n#include <vector>\n#include <nlohmann/json.hpp>\nusing json = nlohmann::json;\n\n";
    for (const auto &nm: typeTelegram.names) {
        out = out + "struct " + nm.name + ";\n";
    }
    out = out + "\n";
    for (const auto &nm: typeTelegram.names) {
        out = out + "//" + nm.description + "\n";
        out = out + "struct " + nm.name + "{\n";
        for (const auto &pa: nm.n) {
            out = out + "\t" + normalize_type(pa.name_type) + " " + pa.parameter + ";\n";
        }
        out = out + "};\n\n";
    }

    for (const auto &nm: typeTelegram.names) {
        out = out + "inline void from_json(const json& j, " + nm.name + "& name);\n";
        out = out + "inline void to_json(json&  j,const " + nm.name + "& name);\n";
    }
    for (const auto &nm: typeTelegram.names) {
        out = out + "inline void from_json(const json& j, " + nm.name + "& name){\n";
        for (const auto &pa: nm.n) {
            if (normalize_type(pa.name_type).find("std::vector") != std::string::npos) {
                out = out + "\t" + normalize_type(pa.name_type) + " " + pa.parameter + ";\n\tif(j.contains(\"" +
                      pa.parameter + "\")){\n";
                out = out + "\t\tfor(const auto a:j.at(\"" + pa.parameter + "\").get<" + normalize_type1(pa.name_type) +
                      ">()){\n\t\t\t" + pa.parameter + ".push_back( std::make_shared<" +
                      normalize_type1(pa.name_type).substr(normalize_type1(pa.name_type).find("<") + 1,
                                                           normalize_type1(pa.name_type).find(">") -
                                                           normalize_type1(pa.name_type).find("<") - 1) +
                      ">(a));\n\t\t}\n\t}\n";
                out = out + "\tname." + pa.parameter + "=" + pa.parameter + ";\n";
            } else {
                if (normalize_type(pa.name_type).find("std::shared") != std::string::npos) {
                    out = out + "\tname." + pa.parameter + "=j.contains(\"" + pa.parameter + "\")?std::make_shared<" +
                          normalize_type1(pa.name_type) +
                          " >(j.at(\"" + pa.parameter + "\").get<" +
                          normalize_type1(pa.name_type) + ">()) : " + gets_default(pa.name_type) + " ;\n";
                } else {
                    out = out + "\tname." + pa.parameter + "=j.contains(\"" + pa.parameter + "\")?j.at(\"" +
                          pa.parameter + "\").get<" +
                          normalize_type1(pa.name_type) + ">() : " + gets_default(pa.name_type) + " ;\n";
                }
            }
        }
        out = out + "}\n";
        out = out + "inline void to_json(json& j,const " + nm.name + "& name){\n";
        out = out + "\tj=json::object();\n";
        for (const auto &pa: nm.n) {
            if (normalize_type(pa.name_type).find("std::vector") != std::string::npos) {
                out = out + "\tfor(auto a:j.at(\"" + pa.parameter + "\").get<" + normalize_type1(pa.name_type) +
                      ">()){\n\t\tauto u=json::object();\n\t\tto_json(u,a) ;\n\t\tj[\"" + pa.parameter +
                      "\"].push_back(u);\n\t}\n";
            } else {
                if (normalize_type(pa.name_type).find("std::shared") != std::string::npos) {
                    out = out + "\tif(name." + pa.parameter + "){to_json(j[\"" + pa.parameter + "\"],*name . " +
                          pa.parameter + ");}\n";
                } else {
                    out = out + "\tj [\"" + pa.parameter + "\"]=name." + pa.parameter + ";\n";
                }
            }
        }
        out = out + "}\n";
    }
    std::fstream outs{"../telegram/include/types_generator.h", std::fstream::out};
    outs << out;
    outs.close();
}

void mySort(std::vector<params> &vec, std::function<bool(const params &, const params &)> comparator) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparator(vec[j], vec[j + 1])) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main(int argc, char **argv) {
    type_generator();
    cpr::Response r = cpr::Get(cpr::Url{"https://core.telegram.org/bots/api"});
    auto text = r.text;
    auto types = text.substr(text.find("Getting updates"), text.size() - text.find("Getting updates"));
    types_telegram typeTelegram;
    while (types.find("<i class=\"anchor-icon\"></i></a>") != std::string::npos) {
        type line;
        std::string find_name = "<i class=\"anchor-icon\"></i></a>";
        std::string name = types.substr(types.find("<i class=\"anchor-icon\"></i></a>") + find_name.size(), 100);
        std::string description = types.substr(types.find("<p>", types.find("<i class=\"anchor-icon\"></i></a>")) + 3,
                                               types.find("</p>", types.find("<i class=\"anchor-icon\"></i></a>")) -
                                               types.find("<p>", types.find("<i class=\"anchor-icon\"></i></a>")) - 3);
        name = name.substr(0, name.find("<"));
        line.description = description;
        if (description.find("Use this method") != std::string::npos ||
            description.find("Informs") != std::string::npos) {
            line.name = name;
            std::string tbody = types.substr(types.find("<tbody>", types.find("<i class=\"anchor-icon\"></i></a>")),
                                             types.find("</tbody>", types.find("<i class=\"anchor-icon\"></i></a>")) -
                                             types.find("<tbody>", types.find("<i class=\"anchor-icon\"></i></a>")));
            while (tbody.find("<tr>") != std::string::npos) {
                std::string tr = tbody.substr(tbody.find("<tr>"), tbody.find("</tr>") - tbody.find("<tr>"));
                std::string param = tr.substr(tr.find("<td>") + 4, tr.find("</td>") - tr.find("<td>") - 4);
                tr.erase(tr.find("<td>"), 1);
                tr.erase(tr.find("</td>"), 1);
                std::string return_typ = tr.substr(tr.find("<td>") + 4, tr.find("</td>") - tr.find("<td>") - 4);
                tr.erase(tr.find("<td>"), 1);
                tr.erase(tr.find("</td>"), 1);
                std::string typ = tr.substr(tr.find("<td>") + 4, tr.find("</td>") - tr.find("<td>") - 4);
                tbody.erase(tbody.find("<tr>"), 1);
                tbody.erase(tbody.find("</tr>"), 1);
                line.n.push_back({param, typ, return_typ});
            }
            typeTelegram.names.push_back(line);
        }
        types.erase(types.find("<i class=\"anchor-icon\"></i></a>"), 1);
    }
    for (int i = 0; i < typeTelegram.names.size(); i++) {
        mySort(typeTelegram.names.at(i).n, [](params a, params b) {
            if (a.name_type == "Yes" && b.name_type == "Optional") {
                return false;
            }
            if (a.name_type == "Optional" && b.name_type == "Yes") {
                return true;
            }
            if (a.name_type == "Yes" && b.name_type == "Yes") {
                return false;
            }
            if (a.name_type == "Optional" && b.name_type == "Optional") {
                return true;
            }
            return true;
        });
    }

    std::string out = "";
    out = out +
          "#include <string>\n#include <memory>\n#include <vector>\n#include <nlohmann/json.hpp>\n#include \"types_generator.h\"\n#include <cpr/cpr.h>\n#include \"network/Network.h\"\nusing json = nlohmann::json;\n\n";
    out = out + "namespace Telegram{\n"
                "\tnamespace Bot{\n"
                "\t\tnamespace Types {\n"
                "#ifndef _WIN32\n"
                "            using __int64 = int64_t;\n"
                "#endif\n"
                "            using json = nlohmann::json;\n"
                "\n"
                "            class API {\n"
                "            public:\n"
                "\n"
                "                API(std::string link, std::shared_ptr<Network> &request) : generalToken(link),\n"
                "                                                                                  request{request} {};\n";
    for (const auto &nm: typeTelegram.names) {
        out = out + "// " + nm.description + "\n";
        out = out + "inline void " + nm.name + "(";
        for (int i = 0; i < nm.n.size(); i++) {
            if (nm.n.at(i).name_type == "Yes") {
                out = out + normalize_type(nm.n.at(i).return_type) + " " + nm.n.at(i).parameter +
                      ((i == nm.n.size() - 1) ? " " : " ,");
            } else {
                out = out + normalize_type(nm.n.at(i).return_type) + " " + nm.n.at(i).parameter +
                      "=" + gets_default(nm.n.at(i).return_type) + ((i == nm.n.size() - 1) ? " " : " ,");
            }
        }
        out = out + ") const{\n";
        out = out + "\tjson payload1; \n";
        for (int i = 0; i < nm.n.size(); i++) {
            if (normalize_type(nm.n.at(i).return_type).find("std::vector<") != std::string::npos) {
                out = out + "\tjson j" + std::to_string(i) + "=json::object();\n if(!" + nm.n.at(i).parameter +
                      ".empty()){";
                out = out + "\tfor(const auto a:" + nm.n.at(i).parameter + "){\n\t\tjson j" + std::to_string(i + 1) +
                      "=json::object() ; \n\t\tto_json(j" + std::to_string(i + 1) + ",*a);\n\t\t" + "j" +
                      std::to_string(i) + ".push_back( j" + std::to_string(i + 1) + " );\n\t}\n";
                out = out + "\tpayload1[\"" + nm.n.at(i).parameter + "\"] = j" + std::to_string(i) + ";\n\t}\n";
            } else {
                if (normalize_type(nm.n.at(i).return_type).find("std::shared_ptr<") != std::string::npos) {
                    out = out + "if(" + nm.n.at(i).parameter + "!=nullptr){";
                    out = out + "\tjson j" + std::to_string(i) + ";\n ";
                    out = out + "\tto_json(j" + std::to_string(i) + ",*" + nm.n.at(i).parameter + ");\n";
                    out = out + "\tpayload1[\"" + nm.n.at(i).parameter + "\"] = j" + std::to_string(i) + ";\n";
                    out = out + "}";
                } else {
                    out = out + "\tpayload1[\"" + nm.n.at(i).parameter + "\"] = " + nm.n.at(i).parameter + ";\n";
                }
            }
        }
        out = out + "\tauto result1=payload1.dump();\n";
        out = out + "auto response = sendHttp(\"/" + nm.name + "\",result1);\n";
        out = out + "}\n\n";
    }
    out = out + "\n"
                "                ~API() {};\n"
                "            private:\n"
                "                std::shared_ptr<Network> &request;\n"
                "                std::string generalToken = \"\";\n"
                "            };\n"
                "        }\n"
                "    }\n"
                "}";
    std::fstream outs1{"../telegram/include/types.h", std::fstream::out};
    outs1 << out;
    outs1.close();
    return 0;
}