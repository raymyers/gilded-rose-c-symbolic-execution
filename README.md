# Gilded Rose with C and Symbolic Execution

See also:

* [Gilded Rose Kata](https://github.com/emilybache/GildedRose-Refactoring-Kata) compilation curated by Emily Bache
* [Gilded Rose in Dafny](https://github.com/raymyers/gilded-rose-dafny) with formal specification.
* [Klee Maze](https://github.com/grese/klee-maze)

## Requirements

  * make and a C compiler such as Clang
  * Docker
  * [Klee](https://klee-se.org/docker/) Docker image

Klee also has a browser runner if you'd like to follow along that way.

## Running tests

This will run the text tests, saving the result to `out.txt` and comparing with `golden.txt`.
```sh
make test
```

To regnenerate the golden.txt, in case of an approved behavior change or system line breaks:
```sh
make golden
```

## Running Klee

Klee will check the implementation in `GildedRose.c` for equivelance with `GildedRoseReference.c` using Symbolic Execution.

Installing Klee is... a bit much. We recommend running in Docker.

```
# Pull image (or build from the official Dockerfile)
docker pull klee/klee 


docker run --rm -ti --ulimit='stack=-1:-1' -v .:/home/klee/app klee/klee
```

Once inside the container with the repo mounted in `./app`, run klee with:

```
cd app

make klee
```
