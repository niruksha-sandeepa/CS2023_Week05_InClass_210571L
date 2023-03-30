#include <iostream>
#include <vector>

using namespace std;

void AddingElement(vector<int> &out, int n);
float GettingMedian(vector<int> out);

int main(){

   int size;
   cout<<"Enter the size of array:";
   cin>>size;
   int arr[size];
   for(int i=0;i<size;i++)
      arr[i]=rand()%100;  //Generate number between 0 to 99
  
   cout<<"\nElements of the array:"<<endl;
   for(int i=0;i<size;i++)
      cout<<arr[i]<<" ";
   cout<<"\n\n";

    vector<int> out;

    for(int n : arr){

        AddingElement(out,n);
        for(int k : out){
            cout<<k<<" ";
        }
        cout<<"\n";
        cout << "Median is ";
        printf("%.2f",GettingMedian(out));
        cout<<"\n\n";
    }
    return 0;
}

void AddingElement(vector<int> &out, int n){
    if (out.size() == 0){
        out.push_back(n);
        return;
    }
    int indexNumber = 0;
    bool isChanged = false;

    for(int i=0;i<out.size();i++){
        if (n < out[i]){
            indexNumber=i;
            isChanged = true;
            break;
        }
    }
    if (! isChanged){
        out.push_back(n);
        return;
    }
    else{
        out.insert(out.begin()+indexNumber,n);
        return;
    }
    return;
}

float GettingMedian(vector<int> out){
    if (out.size()%2==1){
        return out[(out.size()-1)/2.0];
    }
    else{
        return ((out[out.size()/2]+out[(out.size()/2)-1])/2.0);
    }
}