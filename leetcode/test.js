let set = new Set();

// 添加元素
set.add(1);
set.add(2);
set.add(3);

// 删除元素
set.delete(1);

// 判断是否存在某个元素
// 输出 false
console.log(set.has(1));
// 输出 true
console.log(set.has(2));

// 遍历元素
for (let item of set) {
    console.log(item);
}
// 输出 2 和 3