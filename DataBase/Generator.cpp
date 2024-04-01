#include "Generator.h"
#include <cstdlib>
#include <ctime>

void DB::generator(int count) {
    std::vector<std::string> fnames;
    std::vector<std::string> names;
    std::vector<std::string> midnames;
    std::vector<std::string> objects;
    std::vector<int> marks(4);
    std::ifstream fnames_file("family_names.txt");
    std::ifstream names_file("names.txt");
    std::ifstream mnames_file("mid_names.txt");
    std::ifstream objects_file("objects.txt");
    std::ofstream out("outfile.txt");

    srand(time(NULL));

    int id = 0, region, data, day, month, byear, finish;
    std::string f, n, m, o;
    char gender;

    while(!(fnames_file.eof() || names_file.eof() || mnames_file.eof())) {
        
        fnames_file >> f;
        fnames.push_back(f);
        
        names_file >> n;
        names.push_back(n);
        
        mnames_file >> m;
        midnames.push_back(m);

        if(!objects_file.eof()) {
            objects_file >> o;
            objects.push_back(o);
        }
    }

    names_file.close();
    fnames_file.close();
    mnames_file.close();
    objects_file.close();

    for(int i = 0; i < count; i++) {
        int N = rand() % names.size();
        f = fnames[rand() % fnames.size()];
        n = names[N];
        m = midnames[rand() % midnames.size()];
        
        if(N >= names.size()/2){
            gender = 'G';
            f += "a";
            size_t pos = m.find("ich");
            if (pos != std::string::npos) {
                m.replace(pos, 3, "na");
            }
        } else {
            gender = 'M';
        }

        region = 1 + rand() % 89;

        byear = 1924 + rand() % 83; 
        month = 1 + rand() % 12;

        if(month == 2) {
            day = 1 + rand() % 29;
        } else if(month % 2 == 0 && month != 2 && month < 8) {
            day = 1 + rand() % 30;
        } else if(month % 2 == 0 && month >= 8) {
            day = 1 + rand() % 31;
        } else if(month % 2 == 1 && month > 8) {
            day = 1 + rand() % 30;
        } else {
            day = 1 + rand() % 31;
        }
        month *= 10000;
        day *= 1000000; 

        data = day + month + byear;
        finish = 16 + byear + rand() % 3; 
        for(int j = 0; j < 4; j++) {
            marks[j] =  70 + rand() % 30;
        }


        auto future_student = new fStudent(id,region,f,n,m,data,finish, objects[0], objects[1], objects[2], objects[3], marks[0], marks[1], marks[2], marks[3], (marks[0] + marks[1] + marks[2] + marks[3])/4.);

        out << future_student->print_to_gen();
        out<<std::endl;
        id++;
        delete future_student;
    }
    
    fnames.clear();
    names.clear();
    midnames.clear();
    objects.clear();
    marks.clear();
    out.close();
}