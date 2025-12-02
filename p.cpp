#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
  int n_files,n_blocks;
  
  cout<<"Enter No. of Blocks: ";
  cin>>n_blocks;
  cout<<"\nEnter No. of Files: ";
  cin>>n_files;

  vector<int>blocks(n_blocks,0),files(n_files,0),allocation(n_files,-1);
  vector<bool>blocks_visited(n_blocks,0);

  cout<<"\n";
  for(int i=0; i<n_blocks; i++){
    cout<<"Enter Block "<<i+1<<" : ";
    cin>>blocks[i];
    cout<<"\n";
  }
  cout<<"\n";
  for(int i=0; i<n_files;i++){
    cout<<"Enter File "<<i+1<<" : ";
    cin>>files[i];
  }
  cout<<"\n";


  for (int i = 0; i < n_files; i++)
  {
    int max_frag = -1,worst_index=-1;
    for(int j=0; j<n_blocks; j++){
      if(!blocks_visited[j] && blocks[j] >= files[i]){
        int frag = blocks[j] - files[i];

        if(frag > max_frag){
          worst_index = j;
          max_frag = frag;
        }
      }
    }

    if(worst_index != -1){
      allocation[i] = worst_index;
      blocks_visited[worst_index] = true;
    }
    
  }

  cout<<"\nFileNo\tFileSize\tBlockNo\tBlockSize\tFragment\n";

  for(int i=0; i<n_files; i++){
    cout<<i+1<<"\t"<<files[i]<<"\t";

    if(allocation[i] != -1){
      int b_index = allocation[i];
      cout<<b_index+1<<"\t"<<blocks[b_index]<<"\t"<<blocks[b_index] - files[i];
    }else{
      cout<<"N/A\t--\t--";
    }
    cout<<"\n";
  }
  

}