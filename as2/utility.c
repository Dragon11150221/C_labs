
#include "utility.h"


struct job * generate_instance(int num_jobs){
  srand(time(NULL));
  struct job *x = (struct job*) calloc (1, sizeof (struct job));
  struct job *head = x;

  for (int i = 0; i < num_jobs; i++){
    x -> completion_time = (rand () % 1000) + 1;
    x -> rejection_cost = (rand () % 1000) + 1;
    if (i != num_jobs -1){
      struct job *a;
      a = (struct job*) calloc (1, sizeof (struct job));
      x-> next = a;
      x = x-> next;
    }
  }

  printf("%d\n", num_jobs);
  printing(head);

  return head;
}

struct job *read_instance(char *inputfilename){

  int num_jobs;
  char INVALID_INPUT[] = "Invalid instance";
  FILE *fp1 = freopen(inputfilename, "r", stdin);
  if (fp1 == NULL){
    printf("File not find");
    exit(EXIT_FAILURE);
  }
	if (scanf("%d", &num_jobs) != 1) {
		printf("\n%s\n", INVALID_INPUT);
    exit(EXIT_FAILURE);
	}

	// check num jobs valid. Print it, if it is valid.
	if (num_jobs < 1 || num_jobs > 1000) {
		printf("\n%s\n", INVALID_INPUT);
    exit(EXIT_FAILURE);
	}

  struct job *x = (struct job*) calloc (1, sizeof (struct job));
  struct job *head = x;

	// read text file with jobs and save to all_jobs
	for (int i = 0; i < num_jobs; i++) {
		// for reading the text file integers
		int pTime, rCost;
		// read two integers for each line

		if (scanf("%d %d", &pTime, &rCost) != 2) {
			printf("\n%s\n", INVALID_INPUT);
      exit(EXIT_FAILURE);
		}
		//check validity. Answer to part 1
		if (pTime < 1 || pTime > 1000 || rCost < 1 || rCost > 1000) {
			printf("\n%s\n", INVALID_INPUT);
      exit(EXIT_FAILURE);
		}
    x -> completion_time = pTime;
    x -> rejection_cost = rCost;
    if (i != num_jobs -1){
      struct job *a;
      a = (struct job*) calloc (1, sizeof (struct job));
      x-> next = a;
      x = x-> next;
    }
	}

  printf("%d\n", num_jobs);
  printing(head);

  fclose(fp1);
  return head;
}

void printing(struct job *head) {
  while (head != NULL) {
    printf("%d %d\n",head-> completion_time, head-> rejection_cost);
    head = head->next;
  }
}
