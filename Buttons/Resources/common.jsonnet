local lookupOrient(params, table) =
  if "orient" in params then
    if params.orient in table then
      table[params.orient]
    else
      table.up
  else
    table.up
;

local getOrientAngle(params) =
  local table = {
    up: 0.0,
    right: 270,
    down: 180,
    left: 90
  };

  lookupOrient(params, table)
;

local getOrientOffset(params) =
  local table = {
    up: [0.0, 0.0],
    right: [0.0, 1.0],
    down: [1.0, 1.0],
    left: [1.0, 0.0]
  };

  lookupOrient(params, table)
;

local add(vecA, vecB) = [
  vecA[0] + vecB[0],
  vecA[1] + vecB[1]
];

local scale(vecA, vecB) = [
  vecA[0] * vecB[0],
  vecA[1] * vecB[1]
];

local getOrientPos(params) =
  if "pos" in params then
    if "size" in params then
      add(scale(getOrientOffset(params), params.size), params.pos)
    else
      add(getOrientOffset(params), params.pos)
  else
    getOrientOffset(params)
;

{
  getOrientTransform(params):: {
    pos: getOrientPos(params),
    rotation: getOrientAngle(params),
    [if "size" in params then "scale"]: params.size
  },

  getPos(params):: {
    [if "pos" in params then "pos"]: params.pos
  },
  
  getPosSize(params):: self.getPos(params) + {
    [if "size" in params then "scale"]: params.size
  },
  
  getTransform(params):: self.getPosSize(params) + {
    [if "rotation" in params then "rotation"]: params.rotation
  },
  
  getPowerInput(params):: {
    [if "in" in params then "in"]: params["in"],
    [if "operator" in params then "operator"]: params.operator,
    [if "on" in params then "on"]: params.on
  }
}
