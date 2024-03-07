#include "Generator.h"
#include <cstdlib>
#include <ctime>

void DB::generator(int count) {
    std::vector<std::string> fnames;
    std::vector<std::string> names;
    std::vector<std::string> midnames;
    std::vector<std::string> objects;
    std::ifstream fnames_file("family_names.txt");
    std::ifstream names_file("names.txt");
    std::ifstream mnames_file("mid_names.txt");
    std::ifstream objects_file("objects.txt");
    std::ofstream out("outfile.txt");

    srand(time(NULL));

    int id = 0, region;
    std::string f, n, m, o;
    char gender;

    while(!(fnames_file.eof() || names_file.eof() || mnames_file.eof())) {
        
        fnames_file >> m;
        fnames.push_back(m);
        
        names_file >> n;
        names.push_back(n);
        
        mnames_file >> m;
        midnames.push_back(m);

        if(!objects_file.eof()) {
            objects_file >> o;
            objects.push_back(o);
        }
    }

    for(int i = 0; i < count; i++) {
        int N = rand() % names.size();
        f = fnames[rand() % fnames.size()];
        n = names[N];
        m = midnames[rand() % midnames.size()];
        
        if(N >= names.size()/2){
            gender = 'G';
            f += "a";
            size_t pos = m.find("ич");
            if (pos != std::string::npos) {
                m.replace(pos, 3, "на");
            }
        } else {
            gender = 'M';
        }

        region = rand() % 89;

        auto future_student = new DB::fStudent(id,f,n,m,region);

        out << future_student->print();

        for(int s = 0; s < 4; s++) out << objects[s] << " | ";

        for(int j = 0; j < 4; j++) out << 70 + rand() % 30 << " | ";
        out<<std::endl;
        id++;
    }
    
    fnames.clear();
    names.clear();
    midnames.clear();
    objects.clear();
    names_file.close();
    fnames_file.close();
    mnames_file.close();
    objects_file.close();
    out.close();
}