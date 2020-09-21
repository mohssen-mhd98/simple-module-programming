#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>
 
 
struct task_struct *task;         //A tructure in sched.h 
struct task_struct *task_child;        //Structure which needed to iterate through task children   
struct list_head *list;            //Structure needed to iterate through the list in each task->children struct 
 
//Init Module function
int iterate_init(void)
{
    printk(KERN_INFO "%s","Module Loaded\n"); 

    //for_each_process() MACRO iterates through each process in the os located in linux\sched\signal.h
    for_each_process( task ){
        printk(KERN_INFO "\n PID: %d PROCESS: %s STATE: %ld",task->pid, task->comm, task->state);
        printk(KERN_INFO "\nPARENT PID: %d PROCESS: %s STATE: %ld",task->real_parent->pid, task->real_parent->comm, task->real_parent->state);

        printk("-----------------------------------------------------"); 
    }    
     
 
    return 0;
 
}//End of Init Module

//Exit Module
void cleanup_exit(void) 
{
 
 
    printk(KERN_INFO "%s","REMOVING MODULE\n");
 
}                //End of Exit Module
 
module_init(iterate_init);   
module_exit(cleanup_exit);   
 
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ITERATE THROUGH ALL PROCESSES/CHILD PROCESSES IN THE OS");
MODULE_AUTHOR("Laerehte");
