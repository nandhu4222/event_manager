#include <stdio.h>
#include <module.h>
#include <evt_mgr.h>

void printModule1(int eventno){
    printf("\nIn Module 1, performing event %d",eventno);
}

void printModule2(int eventno){
    printf("\nIn Module 2, performing event %d",eventno);
}

void printModule3(int eventno){
    printf("\nIn Module 3, performing event %d",eventno);
}

void printModule4(int eventno){
    printf("\nIn Module 4, performing event %d",eventno);
}

void printModule5(int eventno){
    printf("\nIn Module 5, performing event %d",eventno);
}

fnptr fnptr_array[]={printModule1,printModule2,printModule3,printModule4,printModule5};

fnptr getfnptr(int i){
	return fnptr_array[i];
}

int get_eventBitMap(char *str){
    int event=0,temp=0,i=0;
    while(str[i]!='\0'){
        if(IS_DIGIT(str[i]))
            temp=(temp*10)+(str[i]-48);
        else if(str[i]==','){
            SET_BIT(event,temp);
            temp=0;
        }
        i++;
    }
    SET_BIT(event,temp);
    return event;
}

void module_init(int event_count){
    char eventno[20];
    for(int moduleno=1;moduleno<=5;moduleno++){
        printf("Enter the events Module %d is interested in: ",moduleno);
        scanf("%s",eventno);
        register_event(moduleno,get_eventBitMap(eventno),getfnptr(moduleno-1));
    }
}

void module_deinit(){
    unregister_event();
}
