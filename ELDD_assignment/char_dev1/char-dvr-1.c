#include<linux/init.h>
#include<linux/module.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>



int deviceno;

int desd_open (struct inode *,struct file *);
int desd_release (struct inode *,struct file *); 
//ssize_t desd_read (struct file *,char __user *,size_t , loff_t *);
//ssize_t desd_write (struct file *,const char __user *,size_t , loff_t *);

//char kbuff[100]; 
struct cdev *desd_cdev;

struct file_operations fops=
{
.owner=THIS_MODULE,
//.read=desd_read,
//.write=desd_write,
.open=desd_open,
.release=desd_release,
};




// start of init module------------------------------------------------------------------------------
 
static int __init chardriver_init(void)
{
	int result;
	int MAJOR;
	int MINOR;

	deviceno=MKDEV(255,0);

	MAJOR = MAJOR(deviceno);
	MINOR = MINOR(deviceno);

	printk(KERN_ALERT" i am char driver init function\t dev no=%d\n",deviceno);
	printk(KERN_ALERT"char device MAJOR = %d, MINOR = %d\n", MAJOR, MINOR);

	result = register_chrdev_region(deviceno,1,"desd"); 

	if(result < 0)	
	{
		printk(KERN_INFO "ERROR \n");
//		exit(-1);
	}

	desd_cdev = cdev_alloc();
	desd_cdev->ops = &fops;	

	result=cdev_add(desd_cdev,deviceno,1);
	
	if(result < 0)	
	{
		printk(KERN_INFO "ERROR \n");
//		exit(-1);
	}

	return 0;
}

static void __exit chardriver_exit(void)
{

	unregister_chrdev_region(deviceno,1);
	cdev_del(desd_cdev);
	printk(KERN_INFO" bye bye char driver ...\n");

	
}

int desd_open(struct inode *inode,struct file *filp )
{
	printk("I am in open function \n");
	return 0;

}

int desd_release(struct inode *inode,struct file *filp )
{
	printk("I am in relese function \n");
	return 0;

}


module_init(chardriver_init);
module_exit(chardriver_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("KAJOL");
MODULE_DESCRIPTION("Q1. of char device driver");



































