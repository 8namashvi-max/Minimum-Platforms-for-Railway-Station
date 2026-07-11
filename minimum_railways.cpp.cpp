#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
using namespace std;

struct train{
    int id;
    int arrival;
    int departure;
    bool type;//1 for exprees and 0 for local
};

bool comparator(train a,train b){
    if(a.arrival==b.arrival){
        return a.type>b.type;
    }
    return a.arrival < b.arrival;
}

int tominutes(string time){
    int hrs=stoi(time.substr(0,2));
    int mins=stoi(time.substr(3,2));
    return hrs*60 + mins;
}

string totime(int mins){
    int hrs=mins/60;
    int min=mins%60;

    string hh = (hrs<10 ? "0":"") + to_string(hrs);
    string mm = (min<10 ? "0":"") + to_string(min);

    return hh + ":" + mm;

}

int main(){
    int n;
    cout<<"Enter the no. of trains:"<<endl;
    cin>>n;
    vector<train> trains(n);

    cout<<"Enter arrival time , departure time, and type of train('1' for express & '0' for local):"<<endl;
    cout<<"Enter time  format HH.MM"<<endl;
    for(int i=0;i<n;i++){
        string arrival_time,departure_time;
        bool type;
        cin>>arrival_time>>departure_time>>type;
        trains[i].arrival=tominutes(arrival_time);
        trains[i].departure=tominutes(departure_time);
        trains[i].type=type;
        trains[i].id=i;
    }

    int buffer=10; //gap between departure of train and arrival of next train

    for(int i=0;i<n;i++){
        trains[i].departure+=buffer;
    }

    sort(trains.begin(),trains.end(),comparator);

    priority_queue< pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>> > pq;
    //stores departure time and platform ids of occupied platforms;

    set<int> available;// stores ids of available platforms

    vector<int> assigned_Platform(n);// store ids of already busy platforms 
    
    int maxPlatforms=0;//hepls in creating new platform ids
    int maxUsed=0; // max platforms used at same time
    int peak_start=0;
    int peak_end=0;

    for(auto &train : trains){

        while(!pq.empty() && pq.top().first <= train.arrival){
            available.insert(pq.top().second);
            pq.pop();
        }

        int assignedID;

        if(!available.empty()){
            if(train.type==1){
                assignedID= *(available.begin()); ///express gets the smallest platform id(i.e. the platform with best facility score);
            }
            else{
                assignedID= *(available.rbegin());//local gets largest platform id(i.e. platform which has currently least facility in available plaforms)
            }
            available.erase(assignedID);
        }
        else{
            maxPlatforms++;//creates new platfrom id along with platform creation since no platform is available;
            assignedID=maxPlatforms;
        }

        assigned_Platform[train.id]=assignedID;

        //since platform gets occupied until departure of current train it must be pushed in occupied heap (pq)

        pq.push({train.departure,assignedID});

        int current=pq.size();
        if(current>maxUsed){
            maxUsed=current;
            peak_start=train.arrival;
            peak_end=pq.top().first;
        }

    }

    map<int,int> m;

    for(int i=0;i<assigned_Platform.size();i++){
        m[assigned_Platform[i]]++;
    }
    int count=0;
    int max_id=0;//platform id that was occupied most
    for(int i=0;i<assigned_Platform.size();i++){
        if(m[assigned_Platform[i]] > count){
            max_id=assigned_Platform[i];
            count=m[assigned_Platform[i]];
        }
    }

    cout<<"Platform Id that was occupied most times:"<<endl;
    cout<<"platform ID:"<< max_id <<" was occupied "<<count<<" times "<<endl;
    cout<<"Minimum Platform Required:"<<maxUsed<<endl<<endl;

    cout<<"Peak time ( the time duration in which max platforms where required):"<<endl;
    cout<<totime(peak_start)<<" to "<<totime(peak_end)<<endl<<endl;

    cout<<"Platforms assigned to each train: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Train "<<i<<"-> Platform "<<assigned_Platform[i]<<endl;
    }

    return 0;
}