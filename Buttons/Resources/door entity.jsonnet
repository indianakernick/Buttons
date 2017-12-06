local common = import "common.jsonnet";

local orientOffset = {
  up: [0.5, 0.0],
  right: [0.0, 0.5],
  down: [0.5, 1.0],
  left: [1.0, 0.5]
};

local orientAngle = {
  up: 0.0,
  right: 270,
  down: 180,
  left: 90
};

local getOrient(params) =
  if "orient" in params then
    params.orient
  else
    "up"
;

function(params) {
  components: {
    Activation: {
      speed: 4
    },
    Door: {},
    DoorRendering: {},
    Transform: {},
    PhysicsBody: {
      [if "pos" in params then "pos"]: common.add(orientOffset[getOrient(params)], params.pos),
      [if "size" in params then "scale"]: params.size,
      rotation: orientAngle[getOrient(params)],
      body: "door body.json"
    },
    PowerInput: common.getPowerInput(params)
  }
}
