package cache

type LFUCache struct {
	capacity   int
	size       int
	minFreq    int
	cache      map[int]*LFUNode
	freqMap    map[int]*LFUNode
	head, tail *LFUNode
}

type LFUNode struct {
	key, value, times int
	prev, next        *LFUNode
}

func initLFUNode(key, value int) *LFUNode {
	return &LFUNode{
		key:   key,
		value: value,
		times: 1,
	}
}

func ConstructorLFU(capacity int) LFUCache {
	tmpl := LFUCache{
		capacity: capacity,
		cache:    make(map[int]*LFUNode, capacity),
		freqMap:  make(map[int]*LFUNode, capacity),
		head:     initLFUNode(0, 0),
		tail:     initLFUNode(0, 0),
	}

	tmpl.head.next = tmpl.tail
	tmpl.tail.prev = tmpl.head
	return tmpl
}

func (this *LFUCache) removeNode(node *LFUNode) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

func (this *LFUCache) addToHead(node *LFUNode) {
	node.prev = this.head
	node.next = this.head.next
	this.head.next.prev = node
	this.head.next = node
}

func (this *LFUCache) removeTail() *LFUNode {
	node := this.tail.prev
	this.removeNode(node)
	return node
}

func (this *LFUCache) moveToHead(node *LFUNode) {
	this.removeNode(node)
	this.addToHead(node)
}

func (this *LFUCache) Get(key int) int {
	if _, ok := this.cache[key]; !ok {
		return -1
	}

	node := this.cache[key]
	node.times++
	this.moveToHead(node)
	return node.value
}

func (this *LFUCache) Put(key int, value int) {
	if _, ok := this.cache[key]; !ok {
		node := initLFUNode(key, value)
		this.cache[key] = node
		this.addToHead(node)
		this.size++
		if this.size > this.capacity {
			removed := this.freqMap[this.minFreq]
			delete(this.cache, removed.key)
			this.size--
		}
		this.minFreq = 1
	} else {
		node := this.cache[key]
		node.value = value
		l := this.freqMap[node.times]

		this.moveToHead(node)
	}
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
