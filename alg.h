#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;
 
template <typename T>
const T Median(T itrBegin, T itrEnd, int n)
{
    T numMiddle=itrBegin;
    size_t mid=0;
    int median=0;

    if((itrEnd-itrBegin)%n!=0 || n==1 || itrBegin==itrEnd)
    {
        return itrEnd;
    }
    else{
        while(itrBegin!=itrEnd)
        {
            sort(itrBegin,itrBegin+n);//1,2,3,10,8,6
            mid=((itrBegin+n)-itrBegin)/2;
            int size =itrBegin+n-itrBegin;
             if (size%2==0)
             {
             median= (*(itrBegin + mid - 1) + *(itrBegin + mid)) / 2;
             }
            else
            {
                median= *(itrBegin + mid);
            }
             *numMiddle=median;
              itrBegin=itrBegin+n;
              numMiddle++;

        }

         return numMiddle;
    }

} 

template <typename T>
   const T Transpose(T itrBegin, T itrEnd)
    {
        int ans=0;
        int size=itrEnd-itrBegin;
        if(size==0) return itrEnd;
            if(size%2==0)
            {
                 while(itrBegin!=itrEnd)
                 {
                   iter_swap(itrBegin,itrBegin+1);
                    itrBegin = itrBegin+2;
                    ans=1;
                 }

            }
            else 
            { 
            while (itrBegin!=itrEnd-1)
            {
                 if(itrBegin==itrEnd-1)
                {
                    break;
                }
               else
               {
                 iter_swap(itrBegin,itrBegin+1);
                 itrBegin=itrBegin+2;
                 ans=0;
             }
             
            }
            }

               if(ans==0) 
               {
                 return itrEnd-1;
               }
                
               else
               {
                 return itrEnd;

               }         
        }

template <typename T,typename U>
     const T Transformations(T itrBegin,T itrEnd, U&& lambda)
     {
          T num=itrBegin;
         while(itrBegin!=itrEnd)
        {
            if(itrBegin==itrEnd || ((itrEnd-itrBegin)%2!=0))
            {
             return itrEnd;
            }
            else
            {
            int resultNumer=lambda(*itrBegin,*(itrBegin+1));//1,2,3,10,8,6---->3,5,13,18,14
            itrBegin=itrBegin+2;
            *num=resultNumer;
            num++;

        }
         }
         return num;

     }




