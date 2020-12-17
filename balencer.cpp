#include <string>
#include <map>
#include <cstring>
#include <libxml/parser.h>
#include <libxml/tree.h>


namespace cfetr{//

class Balencer{
public:
    Balencer(){};
    ~Balencer();
    int init(std::string cpusdef, std::string moudlesdef);
    int rebalencer();
private:
    std::map<std::string,Cpu> cpus;
    std::map<std::string,Moudle> moudles;
}

balencer::init(std::string cpusdef, std::string moudlesdef){
//prase cpus xml
    xmlDocPtr cpus_doc=NULL;
    cpus_doc=xmlReadFile(cpusdef.c_str(),NULL,XML_PARSE_NOBLANKS);
    xmlNodePtr node = xmlDocGetRootElement(cpus_doc);//cpus node
    try{
        if(NULL==node) throw -1;
        if((xmlStrcmp(node->name, BAD_CAST"cpus") throw -2;
        node = node->xmlChildrenNode;//cpu node
        while(NULL!=node){
            if(!xmlStrcmp(node->name, BAD_CAST"cpu")){

                std::string id = xmlGetProp(node,"id");
                xmlNodePtr node = node->xmlChildrenNode;
                std::string attr;
                int cycle;
                while(NULL!=node){
                    if("attr"==node->name)
                        attr = BAD_CAST xmlNodeGetContent(node);
                    if("cycle"==node->name)
                        cycle = atoi(BAD_CAST xmlNodeGetContent(node));
                    node=node->next;
                    }
                Cpu c(id,attr,cycle);
                cpus.push_back(c);
            }
            
        }
    }
    catch(int err){
        xmlFreeDoc(cpus_doc);
        std::cout<<"cpus xml parse error:"<<err<<std::endl;
    }
    xmlNodePtr cups_node = cpus_root->children;
    xmlFreeDoc(cpus_doc);
//prase moudles xml
    xmlDocPtr moudles_doc=NULL;
    moudles_doc=xmlReadFile(moudlesdef.c_str(),NULL,XML_PARSE_NOBLANKS);
    xmlNodePtr moudles_node = xmlDocGetRootElement(moudles_doc);
    xmlFreeDoc(moudles_doc);
//allocate





}
}//namespace 