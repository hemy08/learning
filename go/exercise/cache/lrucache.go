package cache

type LRUCache struct {
	capacity   int
	size       int
	cache      map[int]*LRUNode
	head, tail *LRUNode
}

type LRUNode struct {
	key, value int
	prev, next *LRUNode
}

func initLRUNode(key, value int) *LRUNode {
	return &LRUNode{
		key:   key,
		value: value,
	}
}

func ConstructorLRU(capacity int) LRUCache {
	tmpl := LRUCache{
		capacity: capacity,
		cache:    make(map[int]*LRUNode, capacity),
		head:     initLRUNode(0, 0),
		tail:     initLRUNode(0, 0),
	}

	tmpl.head.next = tmpl.tail
	tmpl.tail.prev = tmpl.head
	return tmpl
}

func (this *LRUCache) removeNode(node *LRUNode) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

func (this *LRUCache) addToHead(node *LRUNode) {
	node.prev = this.head
	node.next = this.head.next
	this.head.next.prev = node
	this.head.next = node
}

func (this *LRUCache) removeTail() *LRUNode {
	node := this.tail.prev
	this.removeNode(node)
	return node
}

func (this *LRUCache) moveToHead(node *LRUNode) {
	this.removeNode(node)
	this.addToHead(node)
}

func (this *LRUCache) Get(key int) int {
	if _, ok := this.cache[key]; !ok {
		return -1
	}

	node := this.cache[key]
	this.moveToHead(node)
	return node.value
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.cache[key]; !ok {
		node := initLRUNode(key, value)
		this.cache[key] = node
		this.addToHead(node)
		this.size++
		if this.size > this.capacity {
			removed := this.removeTail()
			delete(this.cache, removed.key)
			this.size--
		}
	} else {
		node := this.cache[key]
		node.value = value
		this.moveToHead(node)
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
