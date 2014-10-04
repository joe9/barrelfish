#include <idris_rts.h>
#include <idris_bitstring.h>
#include <idris_stdfgn.h>
#include <assert.h>
void _idris_FalseElim(VM*, VAL*);
void _idris_Main_46_main(VM*, VAL*);
void _idris_mkForeignPrim(VM*, VAL*);
void _idris_mkLazyForeignPrim(VM*, VAL*);
void _idris_Prelude_46_putStr(VM*, VAL*);
void _idris_run_95__95_IO(VM*, VAL*);
void _idris_unsafePerformPrimIO(VM*, VAL*);
void _idris__123_APPLY0_125_(VM*, VAL*);
void _idris__123_EVAL0_125_(VM*, VAL*);
void _idris__123_runMain0_125_(VM*, VAL*);
void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_Char_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM*, VAL*);
void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_Float_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM*, VAL*);
void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_Int_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM*, VAL*);
void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_Integer_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM*, VAL*);
void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_String_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM*, VAL*);
void _idris_FalseElim(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}

void _idris_Main_46_main(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    LOC(0) = MKSTR(vm, "hello world again""\x0a""");
    allocCon(REG1, vm, 65615, 1, 0);
    SETARG(REG1, 0, LOC(0)); 
    RVAL = REG1;
    TOPBASE(0);
    REBASE;
}

void _idris_mkForeignPrim(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}

void _idris_mkLazyForeignPrim(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}

void _idris_Prelude_46_putStr(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    putStr(GETSTR(LOC(0)));
    TOPBASE(0);
    REBASE;
}

void _idris_run_95__95_IO(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    LOC(1) = NULL_CON(0);
    RESERVE(2);
    TOP(0) = LOC(0);
    TOP(1) = LOC(1);
    SLIDE(vm, 2);
    TOPBASE(2);
    TAILCALL(_idris__123_APPLY0_125_);
}

void _idris_unsafePerformPrimIO(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}

void _idris__123_APPLY0_125_(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    switch(TAG(LOC(0))) {
    case 65615:
        PROJECT(vm, LOC(0), 2, 1);
        RESERVE(2);
        TOP(0) = LOC(2);
        TOP(1) = LOC(1);
        SLIDE(vm, 2);
        TOPBASE(2);
        TAILCALL(_idris_Prelude_46_putStr);
        break;
    default:
        RVAL = NULL;
        TOPBASE(0);
        REBASE;
        break;
    }
}

void _idris__123_EVAL0_125_(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    switch(TAG(LOC(0))) {
    default:
        RVAL = LOC(0);
        TOPBASE(0);
        REBASE;
        break;
    }
}

void _idris__123_runMain0_125_(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(2);
    ADDTOP(2);
    STOREOLD;
    BASETOP(0);
    CALL(_idris_Main_46_main);
    LOC(0) = RVAL;
    LOC(1) = NULL_CON(0);
    RESERVE(2);
    TOP(0) = LOC(0);
    TOP(1) = LOC(1);
    STOREOLD;
    BASETOP(0);
    ADDTOP(2);
    CALL(_idris__123_APPLY0_125_);
    LOC(0) = RVAL;
    RESERVE(1);
    TOP(0) = LOC(0);
    SLIDE(vm, 1);
    TOPBASE(1);
    TAILCALL(_idris__123_EVAL0_125_);
}

void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_Char_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}

void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_Float_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}

void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_Int_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}

void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_Integer_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}

void _idris_Decidable_46_Equality_46__64_Decidable_46_Equality_46_DecEq_36_String_58__33_decEq_58_0_58_primitiveNotEq_58_0(VM* vm, VAL* oldbase) {
    INITFRAME;
    RESERVE(1);
    ADDTOP(1);
    RVAL = NULL;
    TOPBASE(0);
    REBASE;
}
