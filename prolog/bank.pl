:- module(bank,
    [
	add/3,
	createMesh/1
    ]).

:- use_foreign_library('libbank.so').

add(A,B,C) :- C is A + B.

