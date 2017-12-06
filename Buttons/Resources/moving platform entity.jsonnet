local common = import "common.jsonnet";

function(params) {
  components: {
    Activation: {},
    MovingPlatformRendering: {},
    Transform: {},
    PhysicsBody: common.getPosSize(params) + {
      body: "platform body.json",
      pos: params.start
    },
    PowerInput: common.getPowerInput(params),
    MovingPlatform: {
      start: params.start,
      end: params.end,
      [if "speed" in params then "speed"]: params.speed,
      [if "waiting time" in params then "waiting time"]: params["waiting time"]
    }
  }
}
