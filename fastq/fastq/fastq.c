//
// fastq.c
// fastq
//
// Created by apple on 2020/12/15.
//

#include "fastq.h"
#include <stdio.h>
#include <math.h>
#include <zlib.h>
#define buff 1024

double sequence_size_in_GB (char *file_abs_path)
{
	return sequence_size_in_MB (file_abs_path) / pow (10, 3);
};

double sequence_size_in_MB (char *file_abs_path)
{
	return sequenct_size_in_KB (file_abs_path) / pow (10, 3);
};

double sequenct_size_in_KB (char *file_abs_path)
{
	return count_base_pairs (file_abs_path) / pow (10, 3);
};

/*
 * 统计碱基序个数
 */
unsigned long count_base_pairs (char *file_abs_path)
{
	unsigned long bp_sum = 0;
	gzFile file = gzopen (file_abs_path, "rb");

	while (!gzeof (file))
	{
		char line_str[buff];

		if ((gzgets (file, line_str, buff) != NULL))
		{
			if (is_valid_base_pair_line (line_str))
			{
				continue;
			}
			unsigned long length;

			length = strlen (line_str);
			bp_sum = bp_sum + length;
		}
	};
	gzclose (file);
	return bp_sum;
};

/*
 * 通过字符过滤非碱基序列行
 */
int is_valid_base_pair_line (const char *line)
{
	char strs[] = { '@', '+', 'F', '#', ':', '?', '<', ',', '>' };
	for (int i = 0; i < strlen (strs); i++)
	{
		char *exist;

		exist = strchr (line, strs[i]);
		if (exist)
		{
			return 1;
		}
	}
	return 0;
};
