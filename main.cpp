#include <iostream>
#include <Header.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include <time.h>
using namespace std;



int main()
{
    while(true)
    {
        int moves = 0;
        cout<<"What size of vector(less than 12): "; //ERROR::check if is valid (later)
        int vectorSize;
        cin>>vectorSize;
        
        Vector<int> vect(vectorSize);                //make stack vector and copy vector
        Vector<int> vectCopy(vectorSize);
        
        srand((int)time(NULL));                             //changes seed to make more random
        
        for(int i=0;i<vectorSize;i++)               //make unshuffled stack
        {
            vect[i]=i;
        }
        while(is_sorted(vect.begin(),vect.end()))         //shuffle stack until sorted
        {
            random_shuffle(vect.begin(), vect.end());
        }
        for(int i=0;i<vectorSize;i++)           //make copy of original vector
        {
            vectCopy[i]=vect[i];
            cout<<vectCopy[i]<<" ";
        }
        while(true)                             //keep flipping vector until sorted
        {
            if(is_sorted(vect.begin(),vect.end()))              //checks if sorted
            {
                cout<<"\nYou win!!!\n";
                break;
            }
            cout<<"\nAfter what slot do you wish to flip the vector?: "; //asks where to flip
            int cut;
            cin>>cut;
            if(cut>vectorSize)                  //ERROR::make sure its over 0 and under vectorSize
            {
                cout<<"Invalid entry, too big.\n\n";
                cut=1;
            }
            
            int count=0;
            for(int i=cut-1;i>=0;i--)           //flips vector at specified point
            {
                vect[count]=vectCopy[i];
                count++;
            }
            for(int i=0;i<vectorSize;i++)       //print out new vector order
            {
                cout<<vect[i]<<" ";
            }
            for(int i=0;i<vectorSize;i++)          //re-initialize copy
            {
                vectCopy[i]=vect[i];
            }
            moves++;
        }
        if(moves==1)                            //displays number of tries
        {
            cout<<"It took you 1 try.\n\n";
        }
        else
        {
            cout<<"It took you "<<moves<<" tries.\n\n";
        }
        cout<<"Would you like to play again?(y/n): ";     //asks to play again
        char again;
        cin>>again;
        if(again=='y'||again=='Y')                     //if wants to play again, continues loop
        {
            cout<<"\n";
            continue;
        }
        else                                    //if not, leaves loop
        {
            break;
        }
    }
    cout<<"Thanks for playing!!!\n";
}
