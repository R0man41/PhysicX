#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define Gravity 9.8
#define PI 3.14159

//Function to print developer information
void developerInfo()
{
    printf(" Introduction\n- Welcome to the Projectile Motion Calculator! This tool allows you to explore the dynamics of projectile motion under various conditions.\n");
    printf("\n Instructions\n- Input Parameters:\n- Enter initial velocity, launch angle, and other parameters.\n");
    printf("\n Units\n- This Program uses SI units.\n");
    printf("\n Error Handling\n- Ensure all input values are numerical.\n- Check for invalid parameter combinations.\n- Contact support if you encounter issues.\n");
    printf("\n Program Insights\n- Explore how changing parameters affects trajectory, time of flight, and maximum height. Learn about the impact of physics on projectile motion.\n");
    printf("\n Contact/Feedback\n- For questions or feedback, contact us at [darrumaan@gmail.com, joelgeorgevarghese30@gmail.com].\n");
    printf("\n Updates and Version History\n- Version 1.0\n");
    printf("\n References\n- [Concepts of Physics, H.C Verma]\n");
    printf("\n Developed by:\n");
    printf("\n- RUMAAN ISHRAT DAR (RA2312703010013, NWC)\n- JOEL GEORGE VARGHESE (RA2311707010024, CORE)\n");
}


int main()
{
    printf("Loading...\n");
    Sleep(3000);  // 3-second delay

    system("clear");    //Clears the screen

    printf("\t\t\t\t\tProjectile Motion Calculator***");
   
    printf("\n\nPress Enter to continue...");
    getchar(); 

    while (1)
    {
        printf("\n\n");
         
        //declaring variables
        double timeofflight, range, maxheight;
        double initialvelocity, angleofprojection;
        double velocityhorizontal, velocityverticle, inclination, projectileanglewithincline;

        //declaring variable for user choice
        int choice;
        
        //display menu for projectile type
        printf("\t\t\t\t\tChoose Case:\n");
        printf("\t\t\t\t\t1. Ground to Ground Projectile\n");
        printf("\t\t\t\t\t2. Inclined Projectile\n");
        printf("\t\t\t\t\t3. About us\n");
        printf("\t\t\t\t\tPress 0 to quit\n");
        printf("\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
         //ground to ground projectile
          
          //user input for initial velocity and angle of projection
            printf("Enter Initial Velocity (in m/s): ");
            scanf("%lf", &initialvelocity);

            printf("Enter Angle of projection (in degree): ");
            scanf("%lf", &angleofprojection);
            angleofprojection = angleofprojection * PI / 180.0;    //convert angle to radians

            //display menu of calculations
            printf("Calculations Available:\n");
            printf("1. Time of Flight\n");
            printf("2. Range\n");
            printf("3. Maximum Height\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
            
                //calculating time of flight
                timeofflight = (2 * initialvelocity * sin(angleofprojection)) / Gravity;
                printf("Time of Flight is: %.2lf sec", timeofflight);
                break;

            case 2:
            
                //calculating range
                range = (pow(initialvelocity, 2) * sin(2 * angleofprojection)) / Gravity;
                printf("Range is: %.2lf m", range);
                break;

            case 3:
            
                //calculating maximum height
                maxheight = (pow(initialvelocity, 2) * pow(sin(angleofprojection), 2)) / (2 * Gravity);
                printf("Maximum Height is: %.2lf m", maxheight);
                break;

            default:
            
                //display message for invalid choice
                printf("Invalid Choice Please Try Again");
            }

            break;

        case 2:
        
            //inclined projectile

            //user input for initial velocity, inclination, angle between projectile and incline
            printf("Enter Initial Velocity (in m/s): ");
            scanf("%lf", &initialvelocity);

            printf("Enter inclination (in degree): ");
            scanf("%lf", &inclination);
            inclination = inclination * PI / 180.0;

            printf("Enter Angle between projectile and incline (in degree): ");
            scanf("%lf", &projectileanglewithincline);
            projectileanglewithincline = projectileanglewithincline * PI / 180.0;

            //calculating horizontal and verticle components of velocity
            velocityverticle = initialvelocity * sin(projectileanglewithincline);
            velocityhorizontal = initialvelocity * cos(projectileanglewithincline);

                        
            //display menu for calculations
            printf("Calculations Available:\n");
            printf("1. Time of Flight\n");
            printf("2. Range\n");
            printf("3. Maximum Height\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
            
                //time of flight on an inclined plane
                timeofflight = (2 * velocityverticle) / Gravity;
                printf("Time of Flight is: %.2lf sec\n", timeofflight);
                break;

            case 2:
            
                //range on an inclined plane
                range = (pow(initialvelocity, 2) * (sin(2 * projectileanglewithincline + inclination) - sin(inclination))) / (Gravity * pow(cos(inclination), 2));
                printf("Range is: %.2lf m\n", range);
                break;

            case 3:
            
                //maximum height on an inclined plan
                maxheight = pow(velocityverticle, 2) / (2 * Gravity);
                printf("Max Height is: %.2lf m\n", maxheight);
                break;

            default:
            
               //display message for invalid choice
                printf("Invalid choice Please Try Again\n");
            }
            
            break;

        case 3:
            developerInfo();
        }

        if (choice == 0)
        {
            printf("Thank you for using the program!");
            break;
        }
        
        if (choice > 3)
        {
            printf("Invalid Choice Please Try Again\n");
        }
       
    }

    return 0;
}
