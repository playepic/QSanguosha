_G["pd"] = print

module("extensions.0tagen", package.seeall)
extension = sgs.Package("0tagen")

tzeus = sgs.General(extension, "tzeus", "god", "10", true)

-- ¤ta - 直接使用技能--{{{1
TaCard = class("TaCard", SkillCard, {
  initialize = function(self)
    SkillCard.initialize(self)
    self.name = "ta"
    self.target_fixed = true
    self.will_throw = false
    self.target_asigned = true -- 无接口
    self.once = true -- 无接口
  end,

	filter = function(self, card, targets, to_select, player)
    return true
  end,

  on_use = function(self, card, room, source, targets)
    pd("ta_card")
  end
})
ta_card = TaCard:create()

Ta = class("Ta", ViewAsSkill, {
  initialize = function(self)
    ViewAsSkill.initialize(self)
    self.name = "ta"
    self.n = 0
  end,

  view_as = function(self, skill, cards)
    if #cards == 0 then
      local acard = ta_card:clone()

      return acard
    end
  end,

	enabled_at_play = function(self, skill, player)
    return true
	end,  

  enabled_at_response = function(self, skill, player, pattern)
    return true
  end
})
ta=Ta:create()
--}}}1
-- ¤tc - TriggerSkill --{{{1
Tc = class("Tc", TriggerSkill, {
  initialize = function(self)
    TriggerSkill.initialize(self)
    self.name = "tc"
    self.events = {sgs.CardUsed} -- CardUsed
  end,
  
  on_trigger = function(self, skill, event, player, data)
    local room = player:getRoom()
    local use = data:toCardUse()
    pd("trigger", use.card:objectName())

    --[[
    pd(event, sgs.CardUsed, sgs.CardResponsed)

    if event == sgs.CardUsed then
      pd("used", data:toCardUse().card:objectName())
    elseif event == sgs.CardResponsed then
      pd("response", data:toCard():objectName())
    end
    --]]
  end
})
tc = Tc:create()
--}}}1

-- ¤addSkill --{{{1
tzeus:addSkill(ta)
tzeus:addSkill(tc)

--}}}1

-- ¤i18n --{{{1
sgs.LoadTranslationTable{
	["tzeus"] = "宙斯",
  ["#tzeus"] = "众神之神",
    ["ta"] = "TestA",
    ["tb"] = "TestB",
    ["tc"] = "TestC",
    ["tshelie"] = "涉猎",
    [":tshelie"] = "数目为10, 可以拿任何牌",
    ["tguhuo"] = "蛊惑",
    [":tguhuo"] = "必定成功",
    ["tguanxing"] = "观星",
    [":tguanxing"] = "数目恒为5，而且可以无限使用。",	
    ["@tguanxing"] = "您是否发动【观星】技能？",
    ["~tguanxing"] = "将其中任意数量的牌以任意顺序置于牌堆顶，其余则以任意顺序置于牌堆底。",
    ["tnalai"] = "拿来",
    [":tnalai"] = "出牌阶段，你可指定一名其他角色，你获得其所有牌。★手牌、装备、判定牌",	
    ["tqingnang"] = "青囊",
    [":tqingnang"] = "与华佗【青囊】的区别是：可以用装备，并且可使用多次。",	
    ["tjijiu"] = "急救",
    [":tjijiu"] = "与华佗【急救】的区别是：不限制花色，自己回合也能用。",	
    ["ttiandao_trs"] = "天道",
    ["ttiandao_effect"] = "天道",
    [":ttiandao_trs"] = "任意一名角色的判定牌生效前，你可以用自己的一张牌替换之。",
    ["@ttiandao_trs"] = "请选择一张牌",
    ["tshenshou"] = "神之手",
    [":tshenshou"] = "从牌堆里摸任意牌",
	["tthor"] = "索尔",
  ["#tthor"] = "雷神",
  ["$gutena"] = "你好么",
}
--}}}1
