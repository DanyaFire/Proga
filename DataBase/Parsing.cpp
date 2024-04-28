#include "Generator.h"

int parsing() {
    std::cout<<"This is a base of future student of Faculty of Mechanics and Mathematics.\n Enter HELP to learn, which commands you can use.\n";
    std::string line, word;
    std::list<std::string> words; 
    DB::DB St;
    std::string fnamer, namer, mnamer;
    int ren, birthday, finish, mark1, mark2, mark3, mark4;
    double mid_mark;

    while(1) {
        words.clear();
        getline(std::cin,line);
        std::stringstream s(line);
        while(s >> word) {
            words.push_back(word);
        }
        auto it = words.begin();

        if(*it == "HELP") {
            if(++it != words.end()) std::cout << "Unknown command! Please, try again!\n";
            else std::cout << "List of commands: \n1. Exit\n2. Generate {Number}\n3. Load\n4. Print\n5. Save\n6. Add [Surname, name, middle_name, region, date of birth, date of ending school, mark 1, mark 2, mark 3, mark 4, middle_mark]\n7.Select[Surname, name, middle_name, region, date of birth, date of ending school, mark 1, mark 2, mark 3, mark 4, middle_mark, mask]\n";
        } 
        else if(*it == "Exit") {
            if(++it != words.end()) std::cout << "Unknown command! Please, try again!\n";
            else break;
        } 
        else if(*it == "Generate") {
            if(++it == words.end()) std::cout << "Unknown command! Please, try again!\n";
            else {
				int number = stoi(*it);
				if(++it != words.end()) {
					std::cout << "Unknown command. Please, try again.\n";
				} else {
					if(DB::generator(number)) std::cout << "Successfully generated!\n";
				}
            }
        } 
        else if(*it == "Load") {
            if(++it != words.end()){
				std::cout << "Unknown command. Please, try again.\n";
			} else {
				if(St.loadDB("outfile.txt")) std::cout << "Successfully loaded!\n";
			}
        } 

        else if(*it == "Print") {
            if(++it != words.end()){
				std::cout << "Unknown command. Please, try again.\n";
			} else {
                std::ofstream out("dataout.txt");
                St.printDB("dataout.txt");
                std::cout << "Successfully printed!\n";
                out.close();
            }
        } 

        else if(*it == "Save") {
            if(++it != words.end()){
				std::cout << "Unknown command. Please, try again.\n";
			} else {
				if(St.saveDB()) std::cout << "Successfully saved!\n";
			}
        } else if(*it == "Add") {
            if(++it != words.end()){
				std::cout << "Unknown command. Please, try again.\n";
			} else {
                std::fstream databaseout("dataout.txt");
                if(!databaseout.is_open()) {
                    std::cout<<"Файл не открылся!";
                    return 1;
                }
                databaseout.seekg(std::ios_base::end);
                std::cout<<"Enter Surname, name, middle name, region, birthday, finish of school, mark1, mark2, mark3, mark4\n";
                std::cin >> fnamer >> namer >> mnamer >> ren >> birthday >> finish >> mark1 >> mark2 >> mark3 >> mark4;
                mid_mark = (mark1 + mark2 + mark3 + mark4)/4.;
                if(St.add(fnamer, namer, mnamer, ren, birthday, finish, mark1, mark2, mark3, mark4, mid_mark)) {
                    std::cout << "Successfully added!\n";
                }
                databaseout.close();
            }

        } else if(*it == "Select") {
            if(++it == words.end()){
				std::cout << "Unknown command. Please, try again.\n";
			} else {
                std::ofstream out("dataout.txt");
                out.clear();
                std::string surname, name = "";
				int is_surname = 0, is_name = 0, param = 0;
				    double rating = 0;
					bool is_rating = 0;
					bool is_greater = false;
					bool is_less = false;
					if(*it == "surname"){
						if(++it == words.end()) {
							std::cout << "Unknown command. Please, try again.\n";
						} else {
							surname = *(it);
							is_surname = 1;
                            param = 1;
						}
                        //(St.select(surname, "", "", int(), int(), int(), int(), int(), int(), int(), double(), is_surname))->printDB("dataout.txt");

                    } else if(*it == "name") {
                        if(++it == words.end()) {
							std::cout << "Unknown command. Please, try again.\n";
						} else {
							name = *(it);
							is_name = 2;
                            param = 2;
						}
                        //(St.select("", name, "", int(), int(), int(), int(), int(), int(), int(), double(), is_name))->printDB("dataout.txt");

                    } else if(*it == "rating") {
                        if(++it == words.end()){
							std::cout << "Unknown command. Please, try again.\n";
						} else {
                            param = 16;
							if(*it != "<" && *it != ">"){
								std::cout << "Unknown command. Please, try again.\n";
							} else {
								if(*it == ">") is_greater = true;
								if(*it == "<") is_less = true;
								if(++it == words.end()){
									std::cout << "Unknown command. Please, try again.\n";
								} else {
                                    is_rating = 16;
                                    rating = stod(*(it));
                                    //double mark = rating;
									if(is_greater) {
                                        while(abs(rating - 100.) > 0.001) {
                                            (St.select("", "", "", int(), int(), int(), int(), int(), int(), int(), rating, is_rating))->printDB("dataout.txt");
                                            rating += 0.2;
                                        }
									} else if(is_less){
                                        while(abs(rating - 70.) > 0.1) {
                                            (St.select("", "", "", int(), int(), int(), int(), int(), int(), int(), rating, is_rating))->printDB("dataout.txt");
                                            rating -= 0.2;
                                            std::cout<<rating<<" ";
                                        }
                                    }
								}
                            }
						}
                    }

                    if(++it != words.end()) {
						while(1){
							if(*(it++) != "&&"){
								std::cout << "Unknown command. Please, try again.\n";
								break;
							}
							if(*it == "surname"){
								if(++it == words.end()) {
									std::cout << "Unknown command. Please, try again.\n";
									break;
								} else {
                                    surname = *(it);
                                    param += 1;
                                }
							} else if(*it == "name"){
								if(++it == words.end()) {
									std::cout << "Unknown command. Please, try again.\n";
									break;
								} else {
                                    name = *(it);
                                    param += 2;
                                }
                            } else if(*it == "rating"){
								if(++it == words.end()){
									std::cout << "Unknown command. Please, try again.\n";
									break;
								} else {
                                    if(*it != "<" && *it != ">") {
										std::cout << "Unknown command. Please, try again.\n";
										break;
									} else {
                                        param += 16;
										if(*it == ">") {
											if(++it == words.end()){
												std::cout << "Unknown command. Please, try again.\n";
												break;
											} else {
											    rating = stof(*(it));
                                                for(double mark = rating; mark < 100 - 1.e-3; mark += 0.1) {
                                                    St.select(surname, name, "", int(), int(), int(), int(), int(), int(), int(), mark, param)->printDB("dataout.txt");
                                                }
                                            }
										} else if(*it == "<"){
											if(++it == words.end()){
												std::cout << "Unknown command. Please, try again.\n";
												break;
											} else {
											    rating = stof(*(it));
                                                for(double mark = 0.; mark < rating + 1.e-3; mark += 0.1) {
                                                    St.select(surname, name, "", int(), int(), int(), int(), int(), int(), int(), mark, param)->printDB("dataout.txt");
                                                }
                                            }
										}
									}
								}
                            } else {
                                std::cout << "Unknown command. Please, try again.\n";
                                break;
                            } if(++it == words.end()) break;
                        }  
                    } 
                out.close();
            St.select(surname, name, "", int(), int(), int(), int(), int(), int(), int(), rating, param)->printDB("dataout.txt");
            }
        } else std::cout << "kdUnknown command. Please, try again.\n";
    }
    words.clear();
    return 0;
}