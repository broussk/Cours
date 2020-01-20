int* copyPositive(int *A, int n, int *nB){
  int i,d;
  nB = 0;
  for(i=0 ; i<n ; i++){
    if(A[i]>0){*nB++}
  }
  B = malloc(sizeof(int)*(nB));
  for(i=0 ; i<n ; i++){
    if(A[i]>0){B[j+1] = A[i];}
  }
}
