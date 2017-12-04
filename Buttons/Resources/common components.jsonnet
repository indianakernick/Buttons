{
  transformParams(params):: {
    [if "pos" in params then "pos"]: params.pos,
    [if "size" in params then "scale"]: params.size,
    [if "rotation" in params then "rotation"]: params.rotation
  },
  
  powerInputParams(params):: {
    [if "in" in params then "in"]: params["in"],
    [if "operator" in params then "operator"]: params.operator,
    [if "on" in params then "on"]: params.on
  }
}
