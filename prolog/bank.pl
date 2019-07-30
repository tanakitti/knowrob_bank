:- module(marker_vis,
    [
	add/3,
	hello/1
    ]).

:- use_foreign_library('libbank.so').

add(A,B,C) :- C is A + B.

