#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/jiffies.h>

static int jiffies_proc_show(struct seq_file *m, void *v) {
    seq_printf(m, "%lu\n", jiffies);
    return 0;
}

static struct proc_ops jiffies_proc_ops = {
    .proc_read = jiffies_proc_show,
};

static int __init jiffies_module_init(void) {
    struct proc_dir_entry *entry;
    entry = proc_create("jiffies", 0, NULL, &jiffies_proc_ops);
    if (!entry) {
        return -ENOMEM;
    }
    return 0;
}

static void __exit jiffies_module_exit(void) {
    remove_proc_entry("jiffies", NULL);
}

module_init(jiffies_module_init);
module_exit(jiffies_module_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Jiffies Module");