#include <stdio.h>

union decision {
    unsigned char flags; 
    struct {             
        unsigned int your_choice:1; 
        unsigned int your_mothers_choice:1;
        unsigned int your_fathers_choice:1;
        unsigned int socially_acceptable:1;
        unsigned int financially_viable:1;
        unsigned int do_you_aptitude:1;
        unsigned int do_you_likeit:1;
        unsigned int decision:1; 
    } field; 
};

// 1. Setting up the switches
union decision input() {
    union decision d;
    d.flags = 0; 
    d.field.your_mothers_choice = 1; 
    d.field.your_fathers_choice = 0; 
    d.field.socially_acceptable = 1; 
    d.field.financially_viable = 1;   
    d.field.do_you_aptitude = 1;     
    d.field.do_you_likeit = 1;       
    
    return d;
}

void make_decision(union decision *d) {
    d->field.your_choice = d->field.do_you_likeit && d->field.do_you_aptitude;
    if (d->field.your_choice && d->field.your_mothers_choice && d->field.financially_viable) {
        d->field.decision = 1; 
    } else {
        d->field.decision = 0; }
}
void print_decision(union decision d) {
    printf("--- The Story of Your Decision ---\n");
    printf("Do you like it? %s\n", d.field.do_you_likeit ? "Yes! " : "No ");
    printf("Can we afford it? %s\n", d.field.financially_viable ? "Yes! " : "Too pricey ");
    printf("Does Mom agree? %s\n", d.field.your_mothers_choice ? "Yes! " : "No ");
    
    printf("\n[FINAL VERDICT]: ");
    if (d.field.decision == 1) {
        printf(" HOORAY! We are doing it! 🎉\n");
    } else {
        printf(" Oh no, it's a skip this time. \n");
    }
}
void print_conclusion_based_on_flags(union decision d) {
    printf("\n--- Looking at the Magic Box Number ---\n");
    printf("Your decision box's secret number is: %d\n", d.flags);
    
    if (d.flags == 255) {
        printf("Interpretation:  Perfect Harmony! Every single switch is ON! 🌟\n");
    } else if (d.flags > 100) {
        printf("Interpretation:  Looking good! Most of the universe aligns with you.\n");
    } else {
        printf("Interpretation:  Tricky situation. Lots of red flags or missing pieces.\n");
    }
}

int main() {
    union decision my_life = input();
    make_decision(&my_life);
    print_decision(my_life);
    print_conclusion_based_on_flags(my_life);
    return 0;
}
