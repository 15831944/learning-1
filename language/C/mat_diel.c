#include<stdio.h>
#include<math.h>
float test;
int i,k;
float cv0[8],cv1[8],cv2[8];
float q1[8],q2[8];
float re[8],com[8];
double td[8];
void epsilon_real(void)
{
 for (i=0;i<k;i++)
 {
  re[i]=(cv0[i]-cv1[i])/(cv0[i]-cv2[i]);
 }
}
void tand(void)
{
 for (i=0;i<k;i++)
 {
  test=1/(cv0[i]-cv1[i]);
  td[i]=cv0[i]*((1/q1[i])-(1/q2[i]))*test;
 }
}
void epsilon_imag(void)
{
 for (i=0;i<k;i++)
 {
  com[i]=q1[i]*q2[i]/(q1[i]+q2[i]);
 }
}
void main(void)
{
 printf("\n introduceti cite coloane aveti <=8");
 scanf("%d",&k);
 printf("\n Introduceti cv0");
 for (i=0;i<k;i++)
 {
  printf("\n %d=",i);
  scanf("%f",&cv0[i]);
 }
 printf("\n Introduceti cv1");
 for (i=0;i<k;i++)
 {
  printf("\n %d=",i);
  scanf("%f",&cv1[i]);
 }
 printf("\n introduceti q1");
 for (i=0;i<k;i++)
 {
  printf("\n %d=",i);
  scanf("%f",&q1[i]);
 }
 printf("\n introduceti cv2");
 for (i=0;i<k;i++)
 {
  printf("\n %d=",i);
  scanf("%f",&cv2[i]);
 }
 printf("\n introduceti q2");
 for (i=0;i<k;i++)
 {
   printf("\n %d=",i);
   scanf("%f",&q2[i]);
 }
 epsilon_real();
 epsilon_imag();
 tand();
 printf("\n");
 for(i=0;i<k;i++) printf("    %.f",cv0[i]);
 printf("\n");
 for(i=0;i<k;i++) printf("    %.3f",cv1[i]);
 printf("\n");
 for(i=0;i<k;i++) printf("    %.3f",q1[i]);
 printf("\n");
 for(i=0;i<k;i++) printf("    %.3f",cv2[i]);
 printf("\n");
 for(i=0;i<k;i++) printf("    %.3f",q2[i]);
 printf("\n");
 for(i=0;i<k;i++) printf("    %.3f",re[i]);
 printf("\n");
 for(i=0;i<k;i++) printf("    %.3f",td[i]);
 printf("\n");
 for(i=0;i<k;i++) printf("    %.3f",com[i]);
}