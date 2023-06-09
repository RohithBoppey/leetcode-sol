function* fibGenerator(current = 0, next = 1) {
  yield current;
  yield* fibGenerator(next, current + next);
}

const gen = fibGenerator();
console.log(gen.next().value); // 0
console.log(gen.next().value); // 1
