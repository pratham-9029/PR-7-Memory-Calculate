
#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class Temp{
    protected:
        vector<T> id;
        vector<string> name;
    public:
       Temp(){
        int size;
        cout << "Enter the number of students: ";
        cin >> size;
        id.resize(size);
        name.resize(size);
        for(int i = 0; i < size; i++){
            cout << "Enter ID for student " << i+1 << ": ";
            cin >> id[i];
            cout << "Enter name for student " << i+1 << ": ";
            cin >> name[i];
        }
       }
};
class Task : public Temp<int>
{
    public:
    void add(){
            int Student_ID;
            string Student_name;
            cout << "Enter Student ID: ";
            cin >> Student_ID;
            cout << "Enter Student Name: ";
            cin >> Student_name;
            id.push_back(Student_ID);
            name.push_back(Student_name);
        }
        void display(){
            cout << "Student ID        Student Name" << endl;
            for(int i = 0; i < id.size(); i++){
                cout << id[i] << "            " << name[i] << endl;
            }
        }
        void search(int studentID){
            for(int i = 0; i < id.size(); i++){
                if(id[i] == studentID){
                    cout << "Student ID: " << id[i]<<endl << "Name: " << name[i] << endl;
                    return;
                }
            }
            cout << "Invalid id!!" << endl;
        }
        void remove(int studentID){
            for(int i = 0; i < id.size(); i++){
                if(id[i] == studentID){
                    id.erase(id.begin() + i);
                    name.erase(name.begin() + i);
                    cout << "Student removed successfully!" << endl;
                    return;
                }
            }
            cout << "Student not found!" << endl;
        }
};
int main()
{
    Task task;
    int choice;
    do{
        cout << "1 . Add Student" << endl;
        cout << "2 . Display All Students" << endl;
        cout << "3 . Search For Student" << endl;
        cout << "4 . Remove Student" << endl;
        cout << "0 . Exit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                task.add();
                break;
            case 2:
                task.display();
                break;
            case 3:
                int id;
                cout << "Enter Student ID to search: ";
                cin >>id;
                task.search(id);
                break;
            case 4:
                cout << "Enter Student ID to remove: ";
                cin >> id;
                task.remove(id);
                break;
            case 0: 
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }while(choice != 0);
    return 0;
}