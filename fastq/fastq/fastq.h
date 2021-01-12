//
// fastq.h
// fastq
// DNA测序文件fastq格式gz文件测序量大小统计
// Created by apple on 2020/12/15.
//

#ifndef fastq_h
#define fastq_h
#include <string.h>
/*
 * 统计fastq文件测序量大小，以GB为单位
 */
double sequence_size_in_GB (char *file_abs_path);

/*
 * 统计fastq文件测序量大小，以MB为单位
 */
double sequence_size_in_MB (char *file_abs_path);

/*
 * 统计fastq文件测序量大小，以KB为单位
 */
double sequenct_size_in_KB (char *file_abs_path);

/*
 * 统计fastq文件碱基个数
 */
unsigned long count_base_pairs (char *file_abs_path);
int is_valid_base_pair_line (const char *line);
#endif /* fastq_h */
