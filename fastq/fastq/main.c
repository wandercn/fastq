// 
// main.c
// fastq
// 
// Created by apple on 2020/12/15.
// 

#include <stdio.h>
#include "fastq.h"
int main (int argc, const char *argv[])
{
	char *file_abs_path1 = "/Users/apple/Downloads/F19W1_R1.fq.gz";
	char *file_abs_path2 = "/Users/apple/Downloads//F19W1_R2.fq.gz";
	double size1, size2;

	size1 = sequence_size_in_GB (file_abs_path1);
	size2 = sequence_size_in_GB (file_abs_path2);
	printf ("get fastq size1 in GB: %lf\n", size1);
	printf ("get fastq size2 in GB: %lf\n", size2);
	printf ("get fastq size in GB: %lf\n", size1 + size2);
	return 0;
}
