int lomuto(int arr[], int l, int h, int p)
// {
//     // putting the element to be pivoted at last 
//     swap(arr[p],arr[h]);
//     int pivot=arr[h];
//     // i represents window of smaller element and j represents window of larger elements than pivot
//     // starting with an empty window of smaller elements
//     int i=l-1; //i starting from -1
//     for(int j=l;j<h;j++)
//     {
//         if(arr[j]<=pivot)
//         {
//             // increasing the size of smaller element's window
//             i++;
//             // putting the smaller ele in smaller's window
//             swap(arr[j],arr[i]);
//         }
//     }
//     // putting the pivot element just after smaller element's window
//     swap(arr[i+1],arr[h]);
//     // returning pivot's index
//     return i+1;
// }