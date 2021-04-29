// Online C compiler to run C program online
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


int NumOfConRange = 0;
void swap(int *xp, int *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printFunction( int StartIndex, int EndIndex, int NumberinRange)
{
            printf("The number of readings in the range %d - %d is %d \n",  StartIndex, EndIndex , NumberinRange);
}

void SortArray(int *ChargingCurrentReadings, int numOfCCReadings)
{
  int next_index=0;
  for (int i=0;i<numOfCCReadings-1;i++)
  {
        next_index=i;
        for (int j=i+1;j<numOfCCReadings;j++)
        {
            if (ChargingCurrentReadings[j]<ChargingCurrentReadings[next_index])
            {
                next_index=j;
            }
        }

        swap(&ChargingCurrentReadings[next_index],&ChargingCurrentReadings[i]);
    }
}

int NumberofContinuousRange( int *ChargingCurrentReadings, int numOfCCReadings)
{
    int StartIndex=0;
    bool IsStart=1;
    int Iscontinuous=1;
    SortArray(ChargingCurrentReadings, numOfCCReadings);
    for (int i=0; i<numOfCCReadings; i++)
    {
          if (IsStart==1)
          {
              StartIndex=ChargingCurrentReadings[i];
              IsStart=0;
          }
          int j=i+1;
          int tempdiff =ChargingCurrentReadings[j]- ChargingCurrentReadings[i];
          if (tempdiff== 0 ||tempdiff== 1)
          {
              Iscontinuous++;
          }
          else
          {
             printFunction(StartIndex,ChargingCurrentReadings[i], Iscontinuous);
             StartIndex= ChargingCurrentReadings[j];
             Iscontinuous=1;
            NumOfConRange++;
          }
    }
  
  return NumOfConRange;
            
}
