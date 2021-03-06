#ifndef TARGET_SIGNAL_H
#define TARGET_SIGNAL_H

#include "cpu.h"

static inline abi_ulong
get_sp_from_cpustate(CPUX86State *state)
{
    return state->regs[R_ESP];
}

#define	TARGET_SS_ONSTACK	0x0001	/* take signal on alternate stack */
#define	TARGET_SS_DISABLE	0x0004	/* disable taking signals on
					   alternate stack */

#define	TARGET_MINSIGSTKSZ	(512 * 4)
#define	TARGET_SIGSTKSZ		(TARGET_MINSIGSTKSZ + 32768)

typedef target_ulong target_mcontext_t; /* dummy */

typedef struct target_ucontext {
	target_sigset_t		uc_sigmask;
	target_mcontext_t	uc_mcontext;
	abi_ulong		uc_link;
	target_stack_t		uc_stack;
	int32_t			uc_flags;
	int32_t			__spare__[4];
} target_ucontext_t;

static inline abi_long
get_mcontext(CPUArchState *regs, target_mcontext_t *mcp, int flags)
{
	fprintf(stderr, "x86_64 doesn't have support for get_mcontext()\n");
	return (-TARGET_ENOSYS);
}

static inline abi_long
set_mcontext(CPUArchState *regs, target_mcontext_t *mcp, int flags)
{
	fprintf(stderr, "x86_64 doesn't have support for set_mcontext()\n");
	return (-TARGET_ENOSYS);
}

static inline abi_long
get_ucontext_sigreturn(CPUArchState *regs, abi_ulong sf_addr,
        target_ucontext_t **ucontext, void **locked_addr)
{
	fprintf(stderr, "x86_64 doesn't have support for do_sigreturn()\n");
	return (-TARGET_ENOSYS);
}

/* Compare to arm/arm/vm_machdep.c cpu_set_upcall_kse() */
static inline void
thread_set_upcall(CPUArchState *regs, abi_ulong entry, abi_ulong arg,
        abi_ulong stack_base, abi_ulong stack_size)
{
	fprintf(stderr, "x86_64 doesn't have support for thread_set_upcall()\n");
}


#endif /* TARGET_SIGNAL_H */
