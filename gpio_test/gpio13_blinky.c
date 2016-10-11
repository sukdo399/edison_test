#include <stdio.h>
#include <fcntl.h>
#define GPIO_DIRECTION_PATH "/sys/class/gpio/gpio%d/direction"
#define GPIO_VALUE_PATH "/sys/class/gpio/gpio%d/value"
#define GPIO_EXPORT_PATH "/sys/class/gpio/export"
#define BUFFER 50
int main(int argc, char **argv){
    int gpio_pin = 40;  //linux
    char gpio_exp_path[BUFFER];
    char gpio_direction_path[BUFFER];
    char gpio_value_path[BUFFER];
    int fd_export, fd_val, fd_dir;
    int err = 0;
    sprintf(gpio_exp_path,GPIO_EXPORT_PATH);
    sprintf(gpio_direction_path,GPIO_DIRECTION_PATH,gpio_pin);
    sprintf(gpio_value_path,GPIO_VALUE_PATH,gpio_pin);
    fd_dir = open(gpio_direction_path,O_WRONLY);
    if(fd_dir < 0){
        perror("Can't Open GPIO Direction File\n");
        fd_export = open(gpio_exp_path,O_WRONLY);
        if(fd_export < 0){
            perror("Can't Open Export File\n");
            return -1;
        }
        else {
            char buf[15];
            sprintf(buf,"%d",gpio_pin);
            err = write(fd_export,buf,sizeof(buf));
            if(err == -1){
                perror("Can't export GPIO\n");
                return err;
            }
        }
    }
    err = write(fd_dir,"out",sizeof("out"));
    if(err == -1){
            perror("Can't set direction\n");
            return err;
    }
    else 
            printf("Set gpio %d direction as out\n",gpio_pin);
    fd_val = open(gpio_value_path,O_WRONLY);
    while(1) {
    	err = write(fd_val,"1",sizeof("1"));
    	if(err == -1) {
    	    perror("Can't set value\n");
    	    return err;
    	}
    	else{
    	    printf("Set gpio %d value as HIGH\n",gpio_pin);
    	}
	sleep(1);
    	err = write(fd_val,"0",sizeof("0"));
    	if(err == -1) {
    	    perror("Can't set value\n");
    	    return err;
    	}
    	else{
    	    printf("Set gpio %d value as LOW\n",gpio_pin);
    	}
	sleep(1);
    }
    return 0;
}
