#ifndef LOG_TREE_H
#define LOG_TREE_H

#include "revision.h"

struct log_info {
	struct commit *commit, *parent;
};

int parse_decorate_color_config(const char *var, const int ofs, const char *value);
void init_log_tree_opt(struct rev_info *);
int log_tree_diff_flush(struct rev_info *);
int log_tree_commit(struct rev_info *, struct commit *);
int log_tree_opt_parse(struct rev_info *, const char **, int);
void show_log(struct rev_info *opt);
void format_decorations(struct strbuf *sb, const struct commit *commit, int use_color);
void format_decorations_simple(struct strbuf *sb, const struct commit *commit, int use_color);
void show_decorations(struct rev_info *opt, struct commit *commit);
void log_write_email_headers(struct rev_info *opt, struct commit *commit,
			     const char **subject_p,
			     const char **extra_headers_p,
			     int *need_8bit_cte_p);
void load_ref_decorations(int flags);

#define FORMAT_PATCH_NAME_MAX 64
void fmt_output_commit(struct strbuf *, struct commit *, struct rev_info *);
void fmt_output_subject(struct strbuf *, const char *subject, struct rev_info *);

#endif
