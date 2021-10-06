/* purposes: Assignment2
 * Authors: Jinglong Zhao
 * Reference: Assignment1
 * Dates: Started on November 22, 2020
          Last modified on November 29, 2020
*/

#include "main.h"

int main(int argc, char *argv[]) {

  int optind, num_jobs, num_workers = 1;
  int haveinputname = 0, haveoutputname = 0;
  char inputfilename[100], outputfilename[100];
  FILE *fp2;
  num_jobs = 0;
  for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++) {
      switch (argv[optind][1]) {
      case 'i':
        sscanf( argv[optind+1], "%s", inputfilename ); haveinputname=1; break;
      case 'o':
        sscanf( argv[optind+1], "%s", outputfilename );haveoutputname=1; break;
      case 'n':
        sscanf( argv[optind+1], "%d", &num_jobs );
        if (num_jobs > 1000 || num_jobs < 1){
          fprintf(stderr, "Usage: %s [-ionm] [file...]|[num]\n", argv[0]);
          exit(EXIT_FAILURE);} break;
      case 'm':
        sscanf( argv[optind+1], "%d", &num_workers ); break;
      default:
        fprintf(stderr, "Usage: %s [-ionm] [file...]|[num]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  if (haveoutputname){
    char * outname = outputfilename;
    fp2 = freopen(outname, "w+", stdout);
  }

  struct job *head;
  if (haveinputname && num_jobs != 0){
    fprintf(stderr, "Usage: %s [-ionm] [file...]|[num]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  else if (haveinputname){
    char * inname = inputfilename;
    printf("%s",outputfilename);
    head = read_instance(inname);
  }
  else if (num_jobs != 0){
    head = generate_instance(num_jobs);
  }
  else{
    // number of all jobs, jobs accepted and jobs rejected
    int length;
    // time, cost and objective integers

  #ifdef INTERFACE
    printf("Enter the number of jobs: ");
  #endif
    if (scanf("%d", &length) != 1) {
      printf("\n%s\n", INVALID_INPUT);
      return -1;
    }

    // check num jobs valid. Print it, if it is valid.
    if (length < 1 || length > 1000) {
      printf("\n%s\n", INVALID_INPUT);
      return -1;
    }

    // make 2D array for jobs using given size
    int all_jobs[length][2];

    // read text file with jobs and save to all_jobs
    for (int i = 0; i < length; i++) {
      // for reading the text file integers
      int pTime, rCost;
      // read two integers for each line
  #ifdef INTERFACE
      printf("Enter processing time and rejection cost: ");
  #endif
      if (scanf("%d %d", &pTime, &rCost) != 2) {
        printf("\n%s\n", INVALID_INPUT);
        return -1;
      }
      //check validity. Answer to part 1
      if (pTime < 1 || pTime > 1000 || rCost < 1 || rCost > 1000) {
        printf("\n%s\n", INVALID_INPUT);
        return -1;
      }
      all_jobs[i][0] = pTime;
      all_jobs[i][1] = rCost;
    }

    //we're done reading from stdin
    //We've saved jobs info in all_jobs and number of jobs in length

    //print the instance as it was read
    printf("%d\n", length);
    for (int i = 0; i < length; i++) {
      printf("%d %d\n", all_jobs[i][0], all_jobs[i][1]);
    }
    if (num_workers == 1){
      best_subset(length,all_jobs);
    }
    else{
      best_subset_m(length,all_jobs,num_workers);
    }
  }
  if (head){
    int length = find_length(head);
    int all_jobs[length][2];
    transfer_data(length, all_jobs, head);
    sort(length, all_jobs);
    freedom(head);

    if (num_workers == 1){
      best_subset(length,all_jobs);
    }
    else{
      best_subset_m(length,all_jobs,num_workers);
    }
  }

  fclose(fp2);
	return 0;
}

int find_length(struct job *s) {
    int i = 0;
    while (s){
        i++;
        s = s -> next;
    }
    return i;
}

void transfer_data(int length, int all_jobs[][2], struct job *head){
  for (int i = 0 ; i < length; i++){
    all_jobs[i][0] = head -> completion_time;
    all_jobs[i][1] = head -> rejection_cost;
    head = head -> next;
  }
}

void sort(int length,int list[][2]){
  // bubble sort from previous lab
  int step,i,temp;
  for(step=0;step<length-1;step++){
    for(i=0;i<length-step-1;i++){
      if(list[i][0]>list[i+1][0]){
        temp=list[i+1][0];
        list[i+1][0]=list[i][0];
        list[i][0]=temp;
        temp=list[i+1][1];
        list[i+1][1]=list[i][1];
        list[i][1]=temp;
      }
    }
  }
}

void freedom(struct job *head){
  struct job *a = head;
  while (head->next!=NULL){
      head = head->next;
      free(a);
      a = head;
  }
  free(head);
}
