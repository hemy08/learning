package tendersystem

import (
	"sort"
	"time"
)

/*
 * 请你设计一个招标系统，需要实现以下几个功能：
 * AddTender(int userId, int projectId, int price):
 *   将投标方 userId 对项目 projectId 的投标金额 price 录入系统；若系统中已存在 userId 对项目 projectId 的投标金额，则不作处理。
 * UpdateTender(int userId, int projectId, int price) :
 *   若系统中存在投标方 userId 对项目 projectId 的投标金额，则将该金额更新为 price，并返回更新前的投标金额；否则请返回 -1。
 * RemoveTender(int userId, int projectId) :
 *   若系统中存在投标方 userId 对项目 projectId 的投标金额，删除该投标记录，返回被删除的投标金额；否则返回 -1
 * QueryTender(int projectId, int price) :
 *   查询并返回系统中项目 projectId 的投标记录中，投标金额大于 price 且最接近 price 的投标方 userId；
 *   若有多个投标方投标金额相同，比较投标方最后一次投标时间，返回投标时间最早的投标方 userId；（AddTender 和 UpdateTender 都是投标）
 *   若不存在符合要求的投标记录，请返回 -1；
 *
 * 示例：
 * 输入：
 * ["TenderSystem","addTender","addTender","addTender","updateTender","updateTender","removeTender","removeTender","addTender","addTender","addTender","queryTender","queryTender"]
 * [[],[1,1,10],[2,2,20],[2,2,30],[1,1,40],[1,3,40],[1,1],[1,3],[1,2,20],[3,2,10],[4,2,40],[2,15],[5,10]]
 * 输出：[null,null,null,null,10,-1,40,-1,null,null,null,2,-1]
 *
 * 示例 2：
 * 输入：["TenderSystem","addTender","addTender","updateTender","queryTender"]
 * [[],[1,1,10],[2,1,20],[1,1,20],[1,10]]
 * 输出：[null,null,null,10,2]
 *
 * 解释：
 * TenderSystem t = TenderSystem()
 * t.AddTender(1,1,10) // 在系统中添加 userId 为 1，projectId 为 1 的投标金额 10
 * t.AddTender(2,1,20) // 在系统中添加 userId 为 2，projectId 为 1 的投标金额 20
 * t.UpdateTender(1,1,20) // 在系统中将 userId 为 1，projectId 为 1 的投标金额更新为 20，并返回更新前的金额 10
 * t.QueryTender(1,10) // 查询系统中 projectId 为 1，投标金额大于 10 且最接近 10 的 userId，1 与 2 均符合条件，由于 userId 1 更新时间晚（虽然 userId 1先做了首次投标，但是取其最后一次更新投标的时间来进行比较），因此返回最早录入系统的 userId 2
 *
 * 提示：
 *          1 <= userId <= 10^4
 *          1 <= projectId <= 10^6
 *          1 <= price <= 10^8
 *          addTender、updateTender、removeTender、queryTender 累计操作数 <= 1000
 * 答题要求：结果可信和过程可信同样重要，您编写的代码需要符合可信的要求（包括通用编码规范、安全编码规范和圈复杂度）。
 */

type TenderData struct {
	userId     int
	projectId  int
	price      int
	tenderTime time.Time
}

type TenderSystem struct {
	data map[int][]TenderData
}

func Constructor() TenderSystem {
	return TenderSystem{
		data: make(map[int][]TenderData),
	}
}

func (tenderSystem *TenderSystem) addTender(userId int, projectId int, price int) {
	item, _ := tenderSystem.data[userId]

	// 不存在，后面直接添加，如果有userId，再找projectId，找到则直接返回，找不到后面会添加
	for _, v := range item {
		if v.projectId == projectId {
			return
		}
	}

	tenderSystem.data[userId] = append(tenderSystem.data[userId], TenderData{
		userId:     userId,
		projectId:  projectId,
		price:      price,
		tenderTime: time.Now(),
	})
}

func (tenderSystem *TenderSystem) updateTender(userId int, projectId int, price int) int {
	item, exist := tenderSystem.data[userId]
	// 不存在，返回-1
	if !exist {
		return -1
	}

	// 存在userID，找projectId，更新
	for i, v := range item {
		if v.projectId == projectId {
			oldPrice := item[i].price
			item[i].price = price
			item[i].tenderTime = time.Now()
			return oldPrice
		}
	}

	return -1
}

func (tenderSystem *TenderSystem) removeTender(userId int, projectId int) int {
	item, exist := tenderSystem.data[userId]
	// 不存在，返回-1
	if !exist {
		return -1
	}

	var newData []TenderData
	price := 0
	for _, v := range item {
		if v.projectId != projectId {
			newData = append(newData, v)
		}

		price = v.price
	}
	if newData != nil {
		tenderSystem.data[userId] = newData
	} else {
		delete(tenderSystem.data, userId)
	}

	return price
}

func (tenderSystem *TenderSystem) queryTender(projectId int, price int) int {
	var tmpData []TenderData
	for _, item := range tenderSystem.data {
		for _, v := range item {
			if v.projectId == projectId {
				if v.price > price {
					tmpData = append(tmpData, v)
				}
			}
		}
	}

	if len(tmpData) == 0 {
		return -1
	}

	sort.Slice(tmpData, func(i, j int) bool {
		if tmpData[i].price < tmpData[j].price {
			return true
		}

		if tmpData[i].price == tmpData[j].price {
			return tmpData[i].tenderTime.Before(tmpData[j].tenderTime)
		}

		return false
	})

	return tmpData[0].userId
}
