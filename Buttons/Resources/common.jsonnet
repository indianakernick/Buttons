{
  lookupOrient(params, table)::
    if "orient" in params then
      if params.orient in table then
        table[params.orient]
      else
        table.up
    else
      table.up
  ,

  getOrientOffset(params)::
    local table = {
      up: [0.0, 0.0],
      right: [0.0, 1.0],
      down: [1.0, 1.0],
      left: [1.0, 0.0]
    };

    $.lookupOrient(params, table)
  ,

  add(vecA, vecB):: [
    vecA[0] + vecB[0],
    vecA[1] + vecB[1]
  ],

  scale(vecA, vecB):: [
    vecA[0] * vecB[0],
    vecA[1] * vecB[1]
  ],

  getOrientPos(params)::
    if "pos" in params then
      $.add($.getOrientOffset(params), params.pos)
    else
      $.getOrientOffset(params)
  ,
  
  getOrientAngle(params)::
    local table = {
      up: 0.0,
      right: 270,
      down: 180,
      left: 90
    };

    $.lookupOrient(params, table)
  ,
  
  getOrientTransform(params):: {
    pos: $.getOrientPos(params),
    rotation: $.getOrientAngle(params)
  },

  getPos(params):: {
    [if "pos" in params then "pos"]: params.pos
  },
  
  getPosSize(params):: self.getPos(params) + {
    [if "size" in params then "scale"]: params.size
  },
  
  getPowerInput(params):: {
    [if "in" in params then "in"]: params["in"],
    [if "operator" in params then "operator"]: params.operator,
    [if "on" in params then "on"]: params.on
  },
  
  getActive(params)::
    if "active" in params then {
      active: params.active
    } else if "on" in params then {
      active: params.on
    } else {}
  ,
  
  checkParams(params, validNames)::
    local paramNames = std.set(std.objectFields(params));
    local invalidNames = std.setDiff(paramNames, std.set(validNames));
  {
    [if (std.length(invalidNames) > 0) then
      error "Invalid parameters: " + invalidNames
    ]:: null
  },
  
  layerNames:: [
    "text",
    "door",
    "switch",
    "player",
    "lock",
    "key",
    "exit",
    "box",
    "button",
    "laser detector",
    "laser emitter",
    "platform",
    "moving platform"
  ],
  
  indexOf(array, item)::
    local find(info, current) =
      if info.found == -1 && item == current then
        {found: info.index, index: info.index + 1}
      else
        {found: info.found, index: info.index + 1}
    ;
    std.foldl(find, array, {found: -1, index: 0}).found
  ,
  
  getDepth(layer)::
    local index = $.indexOf($.layerNames, layer);
    if index == -1 then
      error "Invalid layer name \"" + layer + "\""
    else
      index / std.length($.layerNames)
}
