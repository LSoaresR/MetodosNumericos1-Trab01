
#include<stdio.h>
#include<math.h>
double F(double x)
{//our function
    return x*x*x- 9*x + 3;
}
double Fd(double x)
{//function's differentiation
    return 3*x*x - 9;
}
int main()
{
    double x0,h,err,root,x1;
    int miter,iter;
    printf("Enter the first approximation ,the max error and the maximum number of iterations\n");
    scanf("%lf%lf%d",&x0,&err,&miter);
    iter=1;
    while(iter<=miter)
    {
        h=F(x0)/Fd(x0);//calculatinf f(x)/f'(x)as we do in Newton Raphson method
        x1=x0-h;//x1=x0-f(x)/f'(x)
        printf("The approximation's value after %d iteration is %.12lf\n",iter,x1);
        if(fabs(h)<err)//If the difference between the 2 approximations is below the max error
        {
            root=x1;//then make the approximation as the root
            break;
        }
        else
        x0=x1;
        iter++;
    }
    if(root==x1)
    {//display root and the function value
        printf("The root is: %.12lf\n",root);
        double fncvalue = F(root);
        printf("Value of F(root) is: %.12lf",fncvalue);
    }
    else
    printf("The unsufficent number of iteration");//In case root!=x1 then number of iteration were insufficient
}
