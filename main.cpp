
#include <iostream>
#include"context.hpp"


//Declare two context objects c and c_main
Context c, c_main; 

//Initialize a counter to count the number of tasks done
int tasks_done = 0; 

void foo() {

    //Print a message and increment the counter
    std::cout << "you called foo" << std::endl;
    tasks_done++;

    //Swap the context to c_main
    swap_context(&c, &c_main); 

}


void goo(){

    
    std::cout<<"you called goo"<<std::endl;
    tasks_done++;

    //Swap the context to c_main
    swap_context(&c,&c_main); 

}

int main() {

    //Get the context of main and store it inside c_main
    get_context(&c_main); 

    //Declare an array of size 4096
    char data[4096]; 

    //Set stack pointer to the end of the array
    char* sp = data + 4096;

    //Align the stack pointer to 16 byte boundary
    sp = reinterpret_cast<char*>((reinterpret_cast<uintptr_t>(sp) & -16L));

    //Adjust sp by 128 bytes 
    sp -= 128;

/*--------------------------------------------------------------------------------------------------*/
    
    char data_goo[4096]; 
    char* sp_goo = data_goo + 4096;

    sp_goo = reinterpret_cast<char*>((reinterpret_cast<uintptr_t>(sp_goo) & -16L));
    sp_goo -= 128;

/*--------------------------------------------------------------------------------------------------*/

    
    while (tasks_done < 2){
        
        if(tasks_done % 2 == 0){

            //set intruction pointer (rip) to foo
            c.rip = reinterpret_cast<void*>(&foo);
            
            //set stack pointer (rsp) to sp
            c.rsp = sp;
            
        }
        else{

            //set intruction pointer (rip) to goo
            c.rip = reinterpret_cast<void*>(&goo);

            //set stack pointer (rsp) to sp_goo
            c.rsp = sp_goo;
            
        }

        //set context to the specified values in c
        set_context(&c);
    }

    return 0;


/*------------------------------------------------------------------------------------------------*/

    
}


