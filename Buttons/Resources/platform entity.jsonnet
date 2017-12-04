function(params) {
  components: {
    PlatformRendering: {},
    Transform: {},
    PhysicsBody: {
      body: "platform body.json",
      [if "pos" in params then "pos"]: params.pos,
      [if "size" in params then "scale"]: params.size
    }
  }
}
