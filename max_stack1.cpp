#include<iostream>
#include<vector>

using namespace std;


class maxStack{
    public:
    int max_ptr,top;
    int arr[1000];

    // Constructor
    maxStack()
    {
        max_ptr = -1;
        top = -1;
    }

    // Push Function
    void push(int x)
    {
        // Checking for the Stack to be empty
        if(top == -1)
        {
            top = 0;
            max_ptr = 0;

            arr[top] = x;
        }

        // If the Stack is not empty
        else
        {
            arr[++top] = x;

            // If the last inserted element in the Stack is greater than the existing max_element,then we change the "max_ptr" accordingly
            if(arr[max_ptr] < x)
                max_ptr = top;
        }
    }

    // Pop() function
    vector<int> pop()
    {
        // If the Stack is empty,that is underflow situation, we return a vector conatining first element as 0 which signifies that the Stack is already empty
        if(top == -1)
        {
            return {0};
        }

        else
        {

            // Checking if this pop() will cause the max element to be changed. If Yes,then we traverse to find the next to-be-max element in the Stack
            if(max_ptr == top)
            {
                int max_elem = INT16_MIN;

                for(int i=top-1;i>=0;i--)
                {
                    if(max_elem < arr[i])
                    {
                        max_elem = arr[i];
                        max_ptr = i;
                    }
                }
            }

            return {1,arr[top--]};
        }
    }

    // Getting the max element from the Stack 
    vector<int> get_Max()
    {
        if(max_ptr == -1)
            return {0};

        else
            return {1,arr[max_ptr]};
    }
};

// Driver Code
int main()
{
    maxStack s1;
    s1.push(10);
    s1.push(11);
    s1.push(13);
    s1.push(-3);
    s1.push(24);
    s1.push(85);

    auto res = s1.get_Max();
    res[0] != 0 ? cout<<"The Maximum Element is: "<<res[1]<<endl : cout<<"The Stack is Empty!!!";

    auto res2 = s1.pop();
    res2[0] != 0 ? cout<<"The Popped Element is: "<<res2[1]<<endl : cout<<"The Stack is Empty!!!";


    res = s1.get_Max();
    res[0] != 0 ? cout<<"The Maximum Element is: "<<res[1]<<endl : cout<<"The Stack is Empty!!!";


    res2 = s1.pop();
    res2[0] != 0 ? cout<<"The Popped Element is: "<<res2[1]<<endl : cout<<"The Stack is Empty!!!";

    res = s1.get_Max();
    res[0] != 0 ? cout<<"The Maximum Element is: "<<res[1]<<endl : cout<<"The Stack is Empty!!!";

    res2 = s1.pop();
    res2[0] != 0 ? cout<<"The Popped Element is: "<<res2[1]<<endl : cout<<"The Stack is Empty!!!";

    res = s1.get_Max();
    res[0] != 0 ? cout<<"The Maximum Element is: "<<res[1]<<endl : cout<<"The Stack is Empty!!!";

    res2 = s1.pop();
    res2[0] != 0 ? cout<<"The Popped Element is: "<<res2[1]<<endl : cout<<"The Stack is Empty!!!";

    res = s1.get_Max();
    res[0] != 0 ? cout<<"The Maximum Element is: "<<res[1]<<endl : cout<<"The Stack is Empty!!!";

    
    return 0;
}