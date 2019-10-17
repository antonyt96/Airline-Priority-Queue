#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;
 
struct node
{
	int priority;
	int me, pp, ffn;
	string ln;
	struct node *link;
};

class Priority_Queue
{
    private:
        node *front;
    public:
        Priority_Queue()
        {
            front = NULL;
        }
       
        void insert(int minEarly, int pricePaid, int ffn, int priority, string ln)
        {
            node *tmp, *q;
            tmp = new node;
            tmp->me=minEarly;
            tmp->pp=pricePaid;
            tmp->ffn=ffn;
            tmp->ln=ln;
            tmp->priority = priority;
            
            
            if (front == NULL || priority < front->priority)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                q = front;
                while (q->link != NULL && q->link->priority <= priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }

        void removeFirst()
        {
            node *tmp;
            if(front == NULL)
                cout<<"Queue empty\n";
            else
            {
                tmp = front;
                cout<<"Deleted item with priority : "<<tmp->priority<<endl;
                front = front->link;
                free(tmp);
            }
        }
        
        void displayAll()
        {
            node *ptr;
            ptr = front;
            if (front == NULL)
                cout<<"Queue is empty\n";
            else
            {
                cout<<"Priority	LastName     " ;
				cout<<"    PricePaid     ";
				cout<<" MinutesEarly     \n";
                while(ptr != NULL)
                {
                    cout<<setw(4)<<ptr->priority<<setw(20)<<ptr->ln<<setw(18)<<ptr->pp<<setw(18)<<ptr->me<<endl;
                    cout<<endl;
                    ptr = ptr->link;
                }
            }
        }
};

int keyValue(int minEarly, int pricePaid, int ffn ){
	
	
	float temp, temp2;
	
	int key;
	
	switch(ffn){
		case 1:
			key=key+40;
			break;
		case 2:
			key=key+30;
			break;
		case 3:
			key=key+20;
			break;
		case 4:
			key=key;
			break;
		default :
			cout<<"Error not valid choice. ";
			return 0;
	}

		
		if(pricePaid>500)
			key=key;
		else if (pricePaid<500.0){
			temp=((500-pricePaid)/50.0)*5;
		 	key=key+temp;	
								}
		else{
			cout<<"Error!"<<endl;
			return 0;
			}
	
		if (minEarly==60)
			key=key;
		else if (minEarly<60){
			temp2=60-minEarly;
			key=key+temp2;
						 }
		else{
			cout<<"Error!"<<endl;
			return 0;
		}
	
	return key;
	
}
int main()
{
    int choice, minEarly, pricePaid, ffn, priority;
    string ln;
    
    Priority_Queue q; 
    do
    {
        cout<<"1.Add Passenger to Queue\n";
        cout<<"2.Remove First Passenger from Queue\n";
        cout<<"3.Display Passengers\n";
        cout<<"4.Terminate\n";
        
        cout<<"Choice : "; 
        cin>>choice;
        switch(choice)
        {
        case 1:
        	cout<<"Enter Last name: ";
        	cin>>ln;
        	cin.ignore();
        	
            cout<<"What is your frequent flyer status? (1:NONE 2:SLVR 3:GOLD 4:PLAT): ";
            cin>>ffn;
            
            cout<<"Price paid for ticket?: ";
			cin>>pricePaid;
            
            cout<<"How many minutes early did you arrive at the gate?: ";
			cin>>minEarly;
            
            
            priority=keyValue(minEarly, pricePaid, ffn);
            q.insert(minEarly, pricePaid, ffn, priority, ln);
            
            break;
        case 2:
            q.removeFirst();
            break;
        case 3:
            q.displayAll();
            break;
        case 4:
            break;
        default :
            cout<<"Wrong choice\n";
        }
    }
    while(choice != 4);
    
    system("PAUSE");
    return 0;
}


