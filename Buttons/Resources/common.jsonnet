{
  getPos(params):: {
    [if "pos" in params then "pos"]: [params.pos[0] - 16, params.pos[1] - 9]
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
